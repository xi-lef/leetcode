#include <ranges>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        ranges::sort(nums);

        const size_t n = nums.size();
        vector<vector<int>> triplets;
        for (size_t i = 0; i < n;) {
            const int a = nums[i];
            if (a > 0)
                break;

            size_t j = i + 1;
            size_t k = n - 1;
            while (j < k) {
                const int b = nums[j];
                const int c = nums[k];
                const int sum = a + b + c;
                if (sum == 0) {
                    triplets.emplace_back(initializer_list{a, b, c});
                    while (++j < n && nums[j] == b) ;
                    while (--k > i && nums[k] == c) ;
                } else if (sum < 0) {
                    while (++j < n && nums[j] + a + c < 0) ;
                } else if (sum > 0) {
                    while (--k > i && nums[k] + a + b > 0) ;
                }
            }

            while (++i < n && nums[i] == a) ;
        }

        return triplets;
    }
};