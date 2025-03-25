class Solution {
public:
    string longestPalindrome(const string& s) {
        const int n = s.size();
        int best = 1;
        int best_start = 0;
        for (int start = 0; start < n - 1; ++start) {
            for (const int offset : {0, 1}) {
                int i = 0;
                while (start - i >= 0 && start + offset + i < n &&
                       s[start - i] == s[start + offset + i]) {
                    ++i;
                }
                --i;
                const int score = 1 + offset + 2 * i;
                if (score > best) {
                    best = score;
                    best_start = start - i;
                }
            }
        }
        return s.substr(best_start, best);
    }
};