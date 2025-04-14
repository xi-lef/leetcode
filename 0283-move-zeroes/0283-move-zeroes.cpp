class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for (int& i : ranges::remove(nums, 0))
            i = 0;
    }
};