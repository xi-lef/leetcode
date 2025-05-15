class Solution {
public:
    int singleNumber(const vector<int>& nums) {
#if 1
        array<int, 32> counts{};
        for (const int& num : nums) {
            for (int i = 0; i < 32; ++i) {
                counts[i] += (num >> i) & 1;
            }
        }

        int answer = 0;
        for (int i = 0; i < 32; ++i) {
            if (counts[i] % 3)
                answer |= 1 << i;
        }
        return answer;
#else
        int ones = 0;
        int twos = 0;
        for (const int& num : nums) {
            for (int i = 0; i < 32; ++i) {
                const int bla = num & (1 << i);
                if (ones & bla) {
                    ones &= ~bla;
                    twos |= bla;
                } else if (twos & bla) {
                    twos &= ~bla;
                } else {
                    ones |= bla;
                }
            }
        }
        return ones;
#endif
    }
};