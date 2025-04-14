class Solution {
public:
    void moveZeroes(vector<int>& nums) {
#if 0
        for (int& i : ranges::remove(nums, 0))
            i = 0;
#else
        int free = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != 0) {
                swap(nums[i], nums[free]);
                ++free;
            }
        }
#endif
    }
};