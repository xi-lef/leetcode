class Solution {
public:
    int countHillValley(const vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int count = 0;
        for (int i = 2; i < nums.size(); ++i) {
            const int& c = nums[i];
            if ((a < b && c < b) || (a > b && c > b))
                ++count;
            if (c != b) {
                a = b;
                b = c;
            }
        }
        return count;
    }
};