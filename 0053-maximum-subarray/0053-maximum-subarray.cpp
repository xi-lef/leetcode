class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = 0;
        int m = INT_MIN;
        for (const int& num : nums) {
            cur += num;
            m = max(m, cur);
            cur = max(cur, 0);
        }
        return m;
    }
};