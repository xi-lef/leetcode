class Solution {
public:
    int numberOfArrays(const vector<int>& differences, int lower, int upper) {
        long ma = 0;
        long mi = 0;
        long x = 0;
        for (const int& i : differences) {
            x += i;
            ma = max(ma, x);
            mi = min(mi, x);
        }
        return max(0l, (upper - lower + 1) - (ma - mi));
    }
};