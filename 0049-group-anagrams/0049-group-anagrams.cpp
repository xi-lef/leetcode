class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        int id = 0;
        unordered_map<string, int> ids{};
        vector<vector<string>> answer{};
        for (const string& s : strs) {
            string copy = s;
            ranges::sort(copy);
            if (!ids.contains(copy)) {
                ids[copy] = id++;
                answer.emplace_back();
            }
            answer[ids[copy]].push_back(s);
        }

        return answer;
    }
};