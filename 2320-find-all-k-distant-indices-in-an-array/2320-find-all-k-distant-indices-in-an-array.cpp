class Solution {
public:
    vector<int> findKDistantIndices(const vector<int>& nums, int key, int k) {
        const int n = nums.size();
        vector<int> answer{};
        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                const int start =
                    max(answer.empty() ? 0 : answer.back() + 1, max(0, i - k));
                const int end = min(n - 1, i + k);
                for (int j = start; j <= end; ++j)
                    answer.push_back(j);
            }
        }

        return answer;
    }
};