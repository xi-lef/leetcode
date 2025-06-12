class Solution {
public:
    int maxAdjacentDistance(const vector<int>& nums) {
        const int n = nums.size();
        int m = 0;
        for (int i = 0; i < n; ++i)
            m = max(m, abs(nums[(i + 1) % n] - nums[i]));
        return m;
    }
};