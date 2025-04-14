class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return ranges::fold_left(nums, 0, bit_xor{});
    }
};