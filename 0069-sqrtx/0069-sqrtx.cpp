class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int h = x;
        while (l <= h) {
            const long m = l + (h - l) / 2;
            const long sq = m * m;
            if (sq == x) {
                return m;
            } else if (sq > x && (m - 1) * (m - 1) < x) {
                return m - 1;
            } else if (sq < x) {
                l = m + 1;
            } else {
                h = m;
            }
        }
        return l;
    }
};