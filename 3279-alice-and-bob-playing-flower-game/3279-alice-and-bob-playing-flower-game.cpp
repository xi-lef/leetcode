class Solution {
public:
    long long flowerGame(int n, int m) {
        return (n + 1ll) / 2 * (m / 2) + (m + 1ll) / 2 * (n / 2);
    }
};