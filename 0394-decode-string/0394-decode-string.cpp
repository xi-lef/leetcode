class Solution {
public:
    // possible improvements:
    // - string_view version
    // - return pair<int, string> for #processedchars
    string decodeString(const string& s) {
        string answer{};
        int depth = 0;
        int repeat = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            const char& c = s[i];
            if (depth > 0 || c == ']') {
                if (c == '[')
                    ++depth;
                else if (c == ']' && --depth < 0)
                    break;
            } else if (isdigit(c)) {
                repeat *= 10;
                repeat += c - '0';
            } else if (c == '[') {
                const string sub = decodeString(s.substr(i + 1));
                while (repeat--)
                    answer += sub;
                repeat = 0;
                ++depth;
            } else { // letter
                answer += c;
            }
        }
        return answer;
    }
};