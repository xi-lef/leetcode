#include <ranges>

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> t_count{};
        for (const char& c : t)
            ++t_count[c];
        --t_count[s[0]];

        const auto check = [&]() {
            return ranges::all_of(views::values(t_count),
                                  [](int i) { return i <= 0; });
        };

        size_t min_start = 0;
        size_t min_len = -1;
        bool good = check();
        int wait_for = -1;
        for (size_t a = 0, b = 0; b < s.size();) {
            if (good) {
                const size_t len = b - a + 1;
                if (len < min_len) {
                    min_len = len;
                    min_start = a;
                }

                if (++t_count[s[a]] > 0) {
                    good = false;
                    wait_for = s[a];
                }
                ++a;
            } else {
                if (++b == s.size())
                    break;
                if (--t_count[s[b]] <= 0) {
                    if (wait_for == -1)
                        good = check();
                    else
                        good = wait_for == s[b];
                }
            }
        }

        return min_len == -1 ? "" : s.substr(min_start, min_len);
    }
};