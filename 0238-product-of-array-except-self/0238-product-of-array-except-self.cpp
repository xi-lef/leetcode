#include <ranges>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);
        for (int pre = 1; const auto& [i, n] : views::enumerate(nums)) {
            pre *= n;
            if (i != nums.size() - 1)
                answer[i + 1] = pre;
        }
        for (int suf = 1;
             const auto& [i, n] : views::reverse(views::enumerate(nums))) {
            suf *= n;
            if (i)
                answer[i - 1] *= suf;
        }
        return answer;
    }
};