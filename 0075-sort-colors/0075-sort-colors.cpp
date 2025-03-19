class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0;
        int one = 0;
        for (int& cur : nums) {
            if (cur == 0) {
                swap(cur, nums[zero]);
                if (one != zero)
                    swap(cur, nums[one]);
                ++zero;
                ++one;
            } else if (cur == 1) {
                swap(cur, nums[one++]);
            }
        }
    }
};