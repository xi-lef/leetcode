class Solution {
public:
    int thirdMax(const vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        int m1 = INT_MIN;
        int m2 = INT_MIN;
        int m3 = INT_MIN;
        bool m1_valid = false;
        bool m2_valid = false;
        bool m3_valid = false;
        for (const int& num : nums) {
            if (!m1_valid || num > m1) {
                m3 = m2;
                m3_valid = m2_valid;
                m2 = m1;
                m2_valid = m1_valid;
                m1 = num;
                m1_valid = true;
            } else if ((!m2_valid || num > m2) && num != m1) {
                m3 = m2;
                m3_valid = m2_valid;
                m2 = num;
                m2_valid = true;
            } else if ((!m3_valid || num > m3) && num != m1 && num != m2) {
                m3 = num;
                m3_valid = true;
            }
        }
        return m3_valid ? m3 : m1;
    }
};