#include <ranges>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        ranges::sort(coins);

        vector<int> best(amount + 1, 100001);
        best[0] = 0;
        for (int a = 1; a <= amount; ++a) {
            for (const int &c : coins) {
                const int prev = a - c;
                if (prev < 0)
                    break;
                best[a] = min(best[a], best[prev] + 1);
            }
        }
        const int ans = best[amount];
        if (ans == 100001) return -1;
        return ans;
    }
};