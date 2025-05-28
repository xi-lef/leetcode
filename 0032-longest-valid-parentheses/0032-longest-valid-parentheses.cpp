class Solution {
public:
    int longestValidParentheses(const string& s) {
        // stack of curs: push cur on ')' and reset to 0, pop+add on '('
        stack<int> vals{};
        int cur = 0;
        int best = 0;

        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == ')') {
                vals.push(cur);
                cur = 0;
            } else if (vals.size() > 0) {
                cur += 2 + vals.top();
                best = max(best, cur);
                vals.pop();
            } else {
                cur = 0;
            }
        }
        return best;
    }
};