#include <ranges>

class Solution {
public:
    vector<int> maxSubsequence(const vector<int>& nums, int k) {
        auto enumerated = views::enumerate(nums) | ranges::to<vector>();
        ranges::nth_element(enumerated, enumerated.begin() + k - 1, greater{},
                            [](const auto& e) { return get<1>(e); });
        ranges::sort(enumerated.begin(), enumerated.begin() + k, {},
                     [](const auto& e) { return get<0>(e); });
        return views::counted(enumerated.begin(), k) | views::elements<1> |
               ranges::to<vector>();
    }
};