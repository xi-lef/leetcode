class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int cur = nums[i];
            while (cur >= 1 && cur <= n && nums[cur - 1] != cur)
                swap(nums[cur - 1], cur);
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return n + 1;
    }
};