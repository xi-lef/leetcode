class Solution {
public:
    int differenceOfSums(int n, int m) {
        const int gauss = n * (n + 1) / 2;
        int num2 = 0;
        for (int i = m; i <= n; i += m)
            num2 += i;
        return gauss - 2 * num2;
    }
};