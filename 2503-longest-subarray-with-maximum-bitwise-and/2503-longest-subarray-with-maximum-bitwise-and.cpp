class Solution {
public:
    int longestSubarray(const vector<int>& nums) {
        int mx = 0;
        int cur = 0;
        int longest = 0;
        for (const int& num : nums) {
            if (num > mx) {
                mx = num;
                longest = 1;
                cur = 1;
            } else if (num == mx) {
                ++cur;
                longest = max(longest, cur);
            } else {
                cur = 0;
            }
        }
        return longest;
    }
};