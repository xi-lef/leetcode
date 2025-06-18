class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        ranges::sort(nums);
        vector<vector<int>> answer{};
        for (int i = 0; i < nums.size(); i += 3) {
            const int a = nums[i];
            const int b = nums[i + 1];
            const int c = nums[i + 2];
            if (c - a > k)
                return {};
            answer.push_back(vector<int>{a, b, c});
        }
        return answer;
    }
};