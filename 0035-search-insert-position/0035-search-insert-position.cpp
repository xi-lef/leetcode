class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size() - 1;
        while (l < h) {
            const int m = l + (h - l) / 2;
            const int n = nums[m];
            if (n == target) {
                return m;
            } else if (n < target) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
        return nums[l] < target ? l + 1 : l;
    }
};