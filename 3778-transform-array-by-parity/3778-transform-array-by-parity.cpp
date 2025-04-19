class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        const int even =
            ranges::count_if(nums, [](const int& i) { return i % 2 == 0; });
        const auto mid = ranges::fill_n(nums.begin(), even, 0);
        ranges::fill_n(mid, nums.size() - even, 1);
        return nums;
    }
};