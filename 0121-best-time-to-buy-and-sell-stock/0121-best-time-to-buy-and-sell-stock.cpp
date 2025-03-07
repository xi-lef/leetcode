#include <ranges>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        vector<int> maxes(prices.size());
        int m = 0;
        for (size_t i = prices.size() - 1;; --i) {
            m = max(m, prices[i]);
            maxes[i] = m;
            if (!i) break;
        }
        int profit = 0;
        for (const auto &[i, price] : views::enumerate(prices)) {
            profit = max(profit, maxes[i] - price);
        }
        return profit;
    }
};