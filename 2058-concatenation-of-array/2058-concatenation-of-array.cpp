class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        const size_t n = nums.size();
        nums.resize(n * 2);
        ranges::copy_n(nums.begin(), n, nums.begin() + n);
        return nums;
    }
};