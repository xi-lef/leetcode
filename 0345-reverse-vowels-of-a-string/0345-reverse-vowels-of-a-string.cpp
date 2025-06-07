class Solution {
public:
    string reverseVowels(string& s) {
        size_t l = 0;
        size_t r = s.size() - 1;
        while (l < r) {
            if (!is_vowel(s[l]))
                ++l;
            else if (!is_vowel(s[r]))
                --r;
            else
                swap(s[l++], s[r--]);
        }
        return s;
    }

private:
    bool is_vowel(char c) { return "aeiouAEIOU"sv.contains(c); }
};