class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n < 0)
            return false;

        int bits = 0;
        for (int i = 0; i < numeric_limits<int>::digits; ++i) {
            bits += (n >> i) & 1;
        }
        return bits == 1;
    }
};