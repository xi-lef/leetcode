#include <ranges>

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ranges::sort(candidates, greater{});
        return combinationSum(candidates, target, 0);
    }

    vector<vector<int>> combinationSum(const vector<int>& candidates,
                                       int target, int i) {
        if (target == 0)
            return {};
        while (i < candidates.size() && candidates[i] > target)
            ++i;
        if (i == candidates.size())
            return {};

        const int cand = candidates[i];
        const int top = target / cand;
        vector<vector<int>> ans{};
        for (int j = 0; j <= top; ++j) {
            auto sub_ans = combinationSum(candidates, target - j * cand, i + 1);
            if (sub_ans.empty())
                continue;

            for (vector<int>& c : sub_ans)
                ranges::fill_n(back_inserter(c), j, cand);
            ranges::move(sub_ans, back_inserter(ans));
        }
        if (target % cand == 0)
            ans.emplace_back(top, cand);
        return ans;
    }
};