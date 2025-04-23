#include <ranges>

class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> count{};
        for (int i = 1; i <= n; ++i) {
            int c = 0;
            for (int v = i; v; v /= 10)
                c += v % 10;
            ++count[c];
        }

        const auto values = count | views::values;
        return ranges::count(values, *ranges::max_element(values));
    }
};