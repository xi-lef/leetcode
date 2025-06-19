class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        ranges::sort(nums);

        int answer = 1;
        int start = nums[0];
        for (const int& num : nums) {
            if (num - start > k) {
                ++answer;
                start = num;
            }
        }
        return answer;
    }
};