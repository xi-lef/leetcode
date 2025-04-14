class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> answer(n + 1, 0);
#if 0
        for (unsigned int i = 0; i <= n; ++i) {
#if 0
            answer[i] = popcount(i);
#else
            int bits = 0;
            for (int j = 0; j < numeric_limits<decltype(i)>::digits; ++j) {
                bits += bool(i & (1 << j));
            }
            answer[i] = bits;
        }
#endif
#else
        int pos = 0;
        int limit = 2;
        for (unsigned int i = 1; i <= n; ++i) {
            answer[i] = answer[pos++] + 1;
            if (i == limit - 1) {
                limit *= 2;
                pos = 0;
            }
        }
#endif
        return answer;
    }
};