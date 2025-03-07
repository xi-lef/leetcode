class Solution {
public:
    bool isPalindrome(string s) {
        size_t a = 0;
        size_t b = s.size() - 1;
        while (a < b) {
            if (!isalnum(s[a])) {
                ++a;
                continue;
            }
            if (!isalnum(s[b])) {
                --b;
                continue;
            }
            if (tolower(s[a++]) != tolower(s[b--])) return false;
        }
        return true;
    }
};