#include <ranges>

class Solution {
public:
    bool equalFrequency(const string& word) {
        unordered_map<char, int> count{};
        for (const char& c : word)
            ++count[c];

        if (count.size() == 1)
            return true;

        const auto beg = count.begin();
        if (count.size() == 2) {
            const int a = beg->second;
            const int b = next(beg)->second;
            return a == 1 || b == 1 || abs(a - b) == 1;
        }

        const int a = beg->second;
        const int b = next(beg)->second;
        const int c = next(beg, 2)->second;
        const int good = a == b ? a : a == c ? a : b;
        bool found = false;
        for (const int& c : count | views::values) {
            if (c != good) {
                if (found)
                    return false;
                if (c - good != 1 && c != 1)
                    return false;
                found = true;
            }
        }
        return good == 1 || found;
    }
};