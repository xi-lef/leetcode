class Solution {
public:
    bool isAnagram(string s, string t) {
        ranges::sort(s);
        ranges::sort(t);
        return s == t;
    }
};