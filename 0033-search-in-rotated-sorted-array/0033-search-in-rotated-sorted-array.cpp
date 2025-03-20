class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();

        int l = 0;
        int u = n;
        while (l < u) {
            const int m = l + (u - l) / 2;
            if (nums[l] < nums[m]) {
                l = m;
            } else {
                u = m;
            }
        }

        ++l %= n;
        u = l;

#if 0
        ranges::rotate(nums, nums.begin() + l);
        auto it = ranges::lower_bound(nums, target);
        if (it == nums.end() || *it != target)
            return -1;
        return (it - nums.begin() + l) % n;
#endif

        do {
            const int m = l < u ? l + (u - l) / 2 : (l + (n - l + u) / 2) % n;
            // const int m = (l + (u - l + (l < u ? 0 : n)) / 2) % n;
            const int v = nums[m];
            if (v < target) {
                l = (m + 1) % n;
            } else if (v > target) {
                u = m;
            } else {
                return m;
            }
        } while (l != u);

        return -1;
    }
};