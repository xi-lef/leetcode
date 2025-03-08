#include <ranges>

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> count;
        for (const char& c : s) {
            ++count[c];
        }
        int total = 0;
        for (const int& c : views::values(count)) {
            total += (c % 2 == 0) ? c : c - 1;
        }
        return total + (total < s.size());
    }
};