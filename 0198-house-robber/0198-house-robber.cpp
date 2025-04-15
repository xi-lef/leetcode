class Solution {
public:
    int rob(vector<int>& nums) {
#if 0
        vector<int> memo(nums.size());
        for (ssize_t i = 0; i < nums.size(); ++i) {
            const int rob = nums[i] + (i >= 2 ? memo[i - 2] : 0);
            const int skip = i > 0 ? memo[i - 1] : 0;
            memo[i] = max(rob, skip);
        }
        return memo.back();
#else
        for (ssize_t i = 0; i < nums.size(); ++i) {
            const int rob = nums[i] + (i >= 2 ? nums[i - 2] : 0);
            const int skip = i > 0 ? nums[i - 1] : 0;
            nums[i] = max(rob, skip);
        }
        return nums.back();
#endif
    }
};