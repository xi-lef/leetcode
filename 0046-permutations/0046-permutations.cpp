class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        ranges::sort(nums);
        vector<vector<int>> answer{};
        do {
            answer.push_back(nums);
        } while (ranges::next_permutation(nums).found);
        return answer;
    }
};