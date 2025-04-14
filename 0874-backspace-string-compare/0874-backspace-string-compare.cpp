class Solution {
public:
    bool backspaceCompare(const string& s, const string& t) {
        ssize_t s_i = s.size() - 1;
        ssize_t t_i = t.size() - 1;
        for (int s_skip = 0, t_skip = 0;;) {
            const auto skip = [](const string& s, ssize_t& i, int& skip) {
                if (i >= 0 && (s[i] == '#' || skip > 0)) {
                    if (s[i] == '#')
                        ++skip;
                    else
                        --skip;
                    --i;
                    return true;
                }
                return false;
            };
            if (skip(s, s_i, s_skip) || skip(t, t_i, t_skip))
                continue;
            if (s_i < 0 || t_i < 0)
                break;
            if (s[s_i--] != t[t_i--])
                return false;
        }
        return s_i == -1 && t_i == -1;
    }
};