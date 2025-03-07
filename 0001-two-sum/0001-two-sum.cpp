#include <ranges>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const size_t n = nums.size();
        for (const int a : views::iota(0uz, n)) {
            for (const int b : views::iota(0uz, n)) {
                if (a != b && nums[a] + nums[b] == target) {
                    return {a, b};
                }
            }
        }
        return {};
    }
};