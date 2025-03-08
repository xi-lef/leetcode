// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#include <ranges>

class Solution {
public:
    int firstBadVersion(int n) {
        return *ranges::lower_bound(views::iota(0l, n + 1l), true, {},
                                    isBadVersion);
    }
};