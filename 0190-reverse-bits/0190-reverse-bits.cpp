class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < numeric_limits<decltype(n)>::digits; ++i) {
            if ((n >> i) & 1)
                ans |= 1 << (31 - i);
        }
        return ans;
    }
};