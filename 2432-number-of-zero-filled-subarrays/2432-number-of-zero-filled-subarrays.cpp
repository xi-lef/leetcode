class Solution {
public:
    long long zeroFilledSubarray(const vector<int>& nums) {
        long long answer = 0;
        int consec_zeros = 0;
        for (const int& num : nums) {
            if (num == 0)
                answer += ++consec_zeros;
            else
                consec_zeros = 0;
        }
        return answer;
    }
};