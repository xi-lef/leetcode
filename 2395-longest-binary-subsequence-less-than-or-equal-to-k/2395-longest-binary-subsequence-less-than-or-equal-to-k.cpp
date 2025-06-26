class Solution {
public:
    int longestSubsequence(string s, int k) {
        int answer = 0;
        int val = 0;
        int pos = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '1') {
                if (val + pos <= k) {
                    val += pos;
                    ++answer;
                }
            } else {
                ++answer;
            }
            if (pos < INT_MAX / 2)
                pos *= 2;
        }
        return answer;
    }
};