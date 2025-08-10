class Solution {
    inline static const auto powers = [] {
        vector<vector<int>> powers(31, vector<int>(10));
        long p = 1;
        for (int i = 0; i < 31; ++i) {
            auto& digits = powers[i];
            for (long x = p; x; x /= 10)
                ++digits[x % 10];

            p *= 2;
        }
        return powers;
    }();

public:
    bool reorderedPowerOf2(int n) {
        vector<int> n_digits(10);
        for (int x = n; x; x /= 10)
            ++n_digits[x % 10];

        return ranges::find(powers, n_digits) != powers.end();
    }
};