class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t j = 0;
        int last = 101;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != last) {
                nums[j++] = nums[i];
            }
            last = nums[i];
        }
        return j;
    }
};