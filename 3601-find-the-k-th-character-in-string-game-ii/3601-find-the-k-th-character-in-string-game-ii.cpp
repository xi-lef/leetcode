class Solution {
public:
    char kthCharacter(long long k, const vector<int>& operations) {
        --k; // zero-indexed now

        int increments = 0;
        for (long long i = 1, j = 0; i <= k; i *= 2) {
            const int op = operations[j++];
            const bool bit = i & k;
            if (op == 1 && bit == 1)
                ++increments;
        }
        return 'a' + increments % 26;
    }
};