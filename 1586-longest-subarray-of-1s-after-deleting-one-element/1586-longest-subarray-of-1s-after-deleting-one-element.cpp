class Solution {
public:
    int longestSubarray(const vector<int>& nums) {
        int a = 0;
        int b = 0;
        bool zero = false;
        int best = 0;
        for (const int& num : nums) {
            if (num == 0) {
                zero = true;
                b = 0;
                swap(a, b);
            } else {
                ++a;
                best = max(best, a + b);
            }
        }
        return best - !zero;
    }
};