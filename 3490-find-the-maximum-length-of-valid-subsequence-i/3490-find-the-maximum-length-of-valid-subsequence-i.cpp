class Solution {
public:
    int maximumLength(const vector<int>& nums) {
#if 1
        int prev_odd = 0;
        int prev_even = 0;
        int prev_odd1 = 1;
        int prev_even1 = 1;
        int length_odd = 0;
        int length_even = 0;
        int length_odd1 = 0;
        int length_even1 = 0;
        for (const int& num : nums) {
            if ((prev_odd + num) % 2 == 1) {
                ++length_odd;
                prev_odd = num;
            }
            if ((prev_odd1 + num) % 2 == 1) {
                ++length_odd1;
                prev_odd1 = num;
            }
            if ((prev_even + num) % 2 == 0) {
                ++length_even;
                prev_even = num;
            }
            if ((prev_even1 + num) % 2 == 0) {
                ++length_even1;
                prev_even1 = num;
            }
        }
        return max({length_odd, length_even, length_odd1, length_even1});
#else
        const auto first_even =
            ranges::find_if(nums, [](const int& n) { return n % 2 == 0; });
        const auto first_odd =
            ranges::find_if(nums, [](const int& n) { return n % 2 == 1; });
        int best = 0;
        if (first_even != nums.end()) {
            best = max(best, solve(nums, first_even - nums.begin(), 0));
            best = max(best, solve(nums, first_even - nums.begin(), 1));
        }
        if (first_odd != nums.end()) {
            best = max(best, solve(nums, first_odd - nums.begin(), 0));
            best = max(best, solve(nums, first_odd - nums.begin(), 1));
        }
        return best;
#endif
    }

private:
    int solve(const vector<int>& nums, int start, int target) {
        int length = 1;
        int prev = nums[start];
        for (int i = start + 1; i < nums.size(); ++i) {
            if ((prev + nums[i]) % 2 == target) {
                ++length;
                prev = nums[i];
            }
        }
        return length;
    }
};