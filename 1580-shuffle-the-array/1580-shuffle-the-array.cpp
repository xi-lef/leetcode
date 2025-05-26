class Solution {
public:
    vector<int> shuffle(const vector<int>& nums, int n) {
        vector<int> answer(nums.size());
        for (int i = 0; i < n; ++i) {
            answer[2 * i] = nums[i];
            answer[2 * i + 1] = nums[n + i];
        }
        return answer;
    }
};