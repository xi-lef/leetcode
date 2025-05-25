class Solution {
public:
    bool wordPattern(const string& pattern, const string& s) {
        unordered_map<char, string> c_to_s{};
        unordered_map<string, char> s_to_c{};
        size_t i = 0;
        for (const char& c : pattern) {
            if (i >= s.size())
                return false;

            size_t j = 1;
            while (i + j < s.size() && s[i + j] != ' ')
                ++j;
            const string word = s.substr(i, j);
            if (word.empty())
                return false;

            if (c_to_s.contains(c)) {
                if (c_to_s[c] != word)
                    return false;
            } else {
                c_to_s[c] = word;
            }
            if (s_to_c.contains(word)) {
                if (s_to_c[word] != c)
                    return false;
            } else {
                s_to_c[word] = c;
            }
            i += j + 1;
        }
        return i == s.size() + 1;
    }
};