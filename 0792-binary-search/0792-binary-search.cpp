#include <ranges>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        const auto i = ranges::lower_bound(nums, target);
        if (i == nums.end() || *i != target) return -1;
        return i - nums.begin();
    }
};