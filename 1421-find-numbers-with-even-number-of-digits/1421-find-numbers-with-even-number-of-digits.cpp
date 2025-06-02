class Solution {
public:
    int findNumbers(const vector<int>& nums) {
        int answer = 0;
        for (int num : nums) {
            bool even = true;
            while (num) {
                even = !even;
                num /= 10;
            }
            answer += even;
        }
        return answer;
    }
};