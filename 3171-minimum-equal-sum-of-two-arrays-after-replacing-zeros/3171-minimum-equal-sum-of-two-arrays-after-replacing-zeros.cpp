class Solution {
public:
    long long minSum(const vector<int>& nums1, const vector<int>& nums2) {
        long long sum1 = 0;
        int zeros1 = 0;
        for (const int& num : nums1) {
            zeros1 += num == 0;
            sum1 += num;
        }
        long long sum2 = 0;
        int zeros2 = 0;
        for (const int& num : nums2) {
            zeros2 += num == 0;
            sum2 += num;
        }

        const long long total1 = sum1 + zeros1;
        const long long total2 = sum2 + zeros2;
        if ((!zeros1 && total2 > sum1) || (!zeros2 && total1 > sum2))
            return -1;
        return max(total1, total2);
    }
};