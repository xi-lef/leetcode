class Solution {
public:
    void merge(vector<int>& nums1, int m, const vector<int>& nums2, int n) {
        int i = 0;
        for (const int& num : nums2) {
            while (i < m && nums1[i] <= num)
                ++i;
            for (int j = m; j > 0 && j > i; --j)
                nums1[j] = nums1[j - 1];

            nums1[i] = num;
            ++m;
        }
    }
};