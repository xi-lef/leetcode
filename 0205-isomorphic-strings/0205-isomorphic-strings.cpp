class Solution {
public:
    bool isIsomorphic(const string& s, const string& t) {
        unordered_map<char, int> s_id{}, t_id{};
        int id = 0;
        for (int i = 0; i < s.size(); ++i) {
            const char c = s[i];
            const char d = t[i];
            const bool s_seen = s_id.contains(c);
            const bool t_seen = t_id.contains(d);
            if (s_seen && t_seen) {
                if (s_id[c] != t_id[d])
                    return false;
            } else if (!s_seen && !t_seen) {
                s_id[c] = t_id[d] = id++;
            } else {
                return false;
            }
        }
        return true;
    }
};