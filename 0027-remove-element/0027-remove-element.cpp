class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
#if 0
        erase(nums, val);
        return nums.size();
#else
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == val) {
                const size_t start = i;
                for (size_t j = i + 1; j < nums.size(); ++j) {
                    if (nums[j] != val) {
                        nums[i++] = nums[j];
                    }
                }
                return i;
            }
        }
        return nums.size();
#endif
    }
};