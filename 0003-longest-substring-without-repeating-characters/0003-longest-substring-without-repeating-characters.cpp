class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int m = 0;
        int start = 0;
        unordered_map<char, int> last{};
        for (int i = 0; i < s.size(); ++i) {
            const bool exists = last.contains(s[i]);
            int& l = last[s[i]];
            if (exists && l >= start) {
                start = l + 1;
            }
            l = i;
            m = max(m, i - start + 1);
        }
        return m;
    }
};