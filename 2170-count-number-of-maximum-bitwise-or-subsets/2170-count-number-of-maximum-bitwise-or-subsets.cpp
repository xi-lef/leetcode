class Solution {
public:
    int countMaxOrSubsets(const vector<int>& nums) {
        const int max_or = ranges::fold_left(nums, 0, bit_or{});
        return solve(nums, max_or, 0, 0);
    }

private:
    int solve(const vector<int>& nums, int max_or, int cur_or, int i) {
        if (i == nums.size())
            return cur_or == max_or;
        if (cur_or == max_or)
            return 1 << (nums.size() - i);
        return solve(nums, max_or, cur_or, i + 1) +
               solve(nums, max_or, cur_or | nums[i], i + 1);
    }
};