class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount == 0)
            return 1;

        vector<long> combs(amount + 1);
        for (const int& c : coins) {
            if (c > amount)
                continue;

            combs[c] += 1;
            for (int i = 1; i + c < combs.size(); ++i) {
                combs[i + c] += combs[i] & 0xffffffff;
            }
        }

        return combs[amount];
    }
};