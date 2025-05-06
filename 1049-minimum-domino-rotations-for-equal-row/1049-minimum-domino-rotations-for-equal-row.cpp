class Solution {
public:
    int minDominoRotations(const vector<int>& tops,
                           const vector<int>& bottoms) {
        const int n = tops.size();
        array<int, 6> x_count, t_count, b_count;
        for (int i = 0; i < n; ++i) {
            const int t = tops[i] - 1;
            const int b = bottoms[i] - 1;
            ++t_count[t];
            ++b_count[b];
            ++x_count[t];
            if (b != t)
                ++x_count[b];
        }
        int most = -1;
        for (int i = 0; i < 6; ++i) {
            if (x_count[i] == n) {
                most = i;
                break;
            }
        }
        if (most == -1)
            return -1;
        return n - max(t_count[most], b_count[most]);
    }
};