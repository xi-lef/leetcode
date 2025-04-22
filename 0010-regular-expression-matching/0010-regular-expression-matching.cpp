class Solution {
public:
    bool isMatch(const string& s, const string& p) {
        return isMatch(string_view{s}, string_view{p});
    }

    unordered_map<string_view, unordered_set<string_view>> seen{};
    bool isMatch(const string_view& s, const string_view& p) {
        if (seen[s].contains(p))
            return false;
        seen[s].insert(p);

        size_t i = 0;
        size_t p_i = 0;
        char prev_p;
        while (i < s.size() || p_i < p.size()) {
            const char re = p[p_i];
            if (p_i < p.size() - 1 && p[p_i + 1] == '*') {
                prev_p = re;
                p_i += 2;
                if (i < s.size() && (s[i] == prev_p || prev_p == '.')) {
                    if (isMatch(s.substr(i + 1), p.substr(p_i - 2)))
                        return true;
                }
                continue;
            } else if (re == '.') {
                if (i == s.size())
                    return false;
            } else if (s[i] != re) {
                return false;
            }
            prev_p = re;
            ++i;
            ++p_i;
        }
        return p_i == p.size();
    }
};