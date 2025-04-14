#include <ranges>

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        const int sum = ranges::fold_left(nums, 0, plus{});
        const int full =
#if 0
            ranges::fold_left(views::iota(1uz, nums.size() + 1), 0, plus{});
#else
            (nums.size() * (nums.size() + 1)) / 2;
#endif
        return full - sum;
    }
};