class Solution {
public:
    vector<int> buildArray(const vector<int>& nums) {
        vector<int> answer(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            answer[i] = nums[nums[i]];
        }
        return answer;
    }
};