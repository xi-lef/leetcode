class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0)
            return 0;

        ranges::sort(nums);
        const int n = nums.size();
        int l = 0;
        int h = nums[n - 1] - nums[0] + 1;
        while (l < h) {
            const int m = l + (h - l) / 2;
            int found = 0;
            for (int i = 1; i < n; ++i) {
                if (nums[i] - nums[i - 1] <= m) {
                    if (++found == p)
                        break;
                    ++i;
                }
            }
            if (found == p)
                h = m;
            else
                l = m + 1;
        }
        return l;
    }
};