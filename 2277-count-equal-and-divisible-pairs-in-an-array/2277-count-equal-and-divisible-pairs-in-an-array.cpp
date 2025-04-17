class Solution {
public:
    int countPairs(const vector<int>& nums, int k) {
        int answer = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if (nums[i] == nums[j] && i * j % k == 0)
                    ++answer;
            }
        }
        return answer;
    }
};