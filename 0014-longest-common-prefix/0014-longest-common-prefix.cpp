class Solution {
public:
    string longestCommonPrefix(const vector<string>& strs) {
        const string& ref = strs[0];
        size_t len = ref.size();
        for (size_t i = 1; i < strs.size(); ++i) {
            const string& s = strs[i];
            if (s.size() < len)
                len = s.size();
            for (size_t j = 0; j < len; ++j) {
                if (s[j] != ref[j]) {
                    if (j == 0)
                        return {};
                    len = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, len);
    }
};