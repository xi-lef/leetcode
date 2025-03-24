class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer{nums};
        subsets(nums, answer, 0);
        answer.push_back({});
        return answer;
    }

    void subsets(vector<int>& nums, vector<vector<int>>& answer, int start) {
        const int n = nums.size();
        if (n == 1)
            return;
        for (int i = start; i < n; ++i) {
            const int save = nums[i];
            nums.erase(nums.begin() + i);
            answer.push_back(nums);
            subsets(nums, answer, i);
            nums.insert(nums.begin() + i, save);
        }
    }
};