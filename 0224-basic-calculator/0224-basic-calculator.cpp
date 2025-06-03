class Solution {
public:
    int calculate(string& s) {
        erase(s, ' ');
        return calc(s + ')').first;
    }

private:
    pair<int, int> calc(string_view s) {
        int answer = 0;
        int depth = 0;
        int num = 0;
        bool prev_digit = false;
        int sign = 1;
        size_t i;
        for (i = 0; i < s.size(); ++i) {
            const char& c = s[i];
            if (prev_digit && !isdigit(c)) {
                answer += sign * num;
                num = 0;
            }
            prev_digit = false;

            if (c == ')') {
                if (--depth < 0)
                    break;
            } else if (c == '(') {
                if (depth++ > 0)
                    continue;
                const auto [res, skip] = calc(s.substr(i + 1));
                answer += sign * res;
                i += skip;
            } else if (depth > 0) {
                continue;
            } else if (c == '-') {
                sign = -1;
            } else if (c == '+') {
                sign = 1;
            } else {
                prev_digit = true;
                num *= 10;
                num += c - '0';
            }
        }
        return {answer, i};
    }
};