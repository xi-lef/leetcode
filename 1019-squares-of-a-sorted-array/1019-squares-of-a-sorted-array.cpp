class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        const size_t n = nums.size();
        ssize_t neg = -1;
        size_t pos = n;
        for (size_t i = 0; i < n; ++i) {
            if (nums[i] < 0) {
                neg = i;
            } else {
                pos = i;
                break;
            }
        }

        vector<int> answer{};
        while (neg > -1 || pos < n) {
            if (neg > -1 && (pos == n || -nums[neg] < nums[pos])) {
                answer.push_back(nums[neg] * nums[neg]);
                --neg;
            } else {
                answer.push_back(nums[pos] * nums[pos]);
                ++pos;
            }
        }
        return answer;
    }
};