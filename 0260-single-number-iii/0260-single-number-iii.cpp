class Solution {
public:
    vector<int> singleNumber(const vector<int>& nums) {
        unsigned int diff = 0;
        for (const int& num : nums)
            diff ^= num;

        const int shift = countr_zero(diff);
        int bit0 = 0;
        int bit1 = 0;
        for (const int& num : nums) {
            if (num & (1 << shift))
                bit1 ^= num;
            else
                bit0 ^= num;
        }
        return {bit0, bit1};
    }
};