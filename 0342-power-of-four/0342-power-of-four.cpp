class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1)
            return false;

        int pos = -1;
        for (int i = 0; i < numeric_limits<int>::digits; ++i) {
            if (n & (1 << i)) {
                if (pos != -1)
                    return false;
                pos = i;
            }
        }
        return pos % 2 == 0;
    }
};