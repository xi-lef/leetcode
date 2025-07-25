class Solution {
public:
    int maxSum(const vector<int>& nums) {
        vector<bool> contains(101);
        int highest = -101;
        int best = 0;
        int cur_sum = 0;
        for (const int& num : nums) {
            highest = max(highest, num);
            if (num <= 0)
                continue;

            if (!contains[num]) {
                contains[num] = true;
                cur_sum += num;
                best = max(best, cur_sum);
            }
        }
        return highest < 0 ? highest : best;
    }
};