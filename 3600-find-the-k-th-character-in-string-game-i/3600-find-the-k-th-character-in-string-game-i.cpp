class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        while (s.size() < k) {
            const int n = s.size();
            for (int i = 0; i < n; ++i)
                s += s[i] == 'z' ? 'a' : s[i] + 1;
        }
        return s[k - 1];
    }
};
