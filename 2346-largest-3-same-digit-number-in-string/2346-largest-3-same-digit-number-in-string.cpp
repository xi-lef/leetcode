class Solution {
public:
    string largestGoodInteger(const string& num) {
        char best = -1;
        char cur = num[0];
        int cur_len = 0;
        for (const char& c : num) {
            if (c == cur) {
                if (++cur_len == 3) {
                    best = max(best, cur);
                }
            } else {
                cur = c;
                cur_len = 1;
            }
        }
        return best == -1 ? "" : string(3, best);
    }
};