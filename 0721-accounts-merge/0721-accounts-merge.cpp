#include <ranges>

class Solution {
public:
    vector<vector<string>>
    accountsMerge(const vector<vector<string>>& accounts) {
        unordered_map<string, unordered_set<int>> mail_ids{};
        for (int i = 0; i < accounts.size(); ++i) {
            const auto& account = accounts[i];
            for (const auto& mail : account | views::drop(1))
                mail_ids[mail].insert(i);
        }

        vector<vector<string>> answer{};
        unordered_set<int> skip{};
        for (int i = 0; i < accounts.size(); ++i) {
            if (skip.contains(i))
                continue;

            vector<string> merged_account{accounts[i][0]};
            set<string> mails{};
            stack<int> dfs{{i}};
            while (!dfs.empty()) {
                int id = dfs.top();
                dfs.pop();
                if (skip.contains(id))
                    continue;
                skip.insert(id);

                const auto& account = accounts[id];
                for (auto& mail : account | views::drop(1)) {
                    mails.insert(move(mail));
                    for (const auto& id : mail_ids[mail])
                        dfs.push(id);
                }
            }
            for (auto& mail : mails)
                merged_account.push_back(move(mail));
            answer.push_back(move(merged_account));
        }

        return answer;
    }
};