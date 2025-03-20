class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ')
            ++i;

        bool pos = true;
        if (s[i] == '+') {
            ++i;
        } else if (s[i] == '-') {
            ++i;
            pos = false;
        }

        while (i < s.size() && s[i] == '0')
            ++i;

        long val = 0;
        for (; i < s.size(); ++i) {
            const char c = s[i];
            if (c < '0' || c > '9')
                break;
            val = 10 * val + (c - '0');
            if (val > INT_MAX) {
                val = static_cast<long>(INT_MAX) + !pos;
                break;
            }
        }
        return pos ? val : -val;
    }
};