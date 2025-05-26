class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n < 1)
            return false;

        int pow = 1;
        for (int i = 0; i < 19; ++i) {
            if (pow == n)
                return true;
            pow *= 3;
        }
        return pow == n;
    }
};