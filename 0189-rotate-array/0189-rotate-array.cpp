class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const size_t n = nums.size();
#if 1
        int start = 0;
        int i = start;
        int tmp = nums[i];
        size_t moved = 0;
        while (moved < n) {
            i = (i + k) % n;
            swap(tmp, nums[i]);
            ++moved;
            if (i == start) {
                ++start;
                tmp = nums[++i %= n];
            }
        }
#else
        vector<int> cpy(n);
        for (int i = 0; i < n; ++i)
            cpy[(i + k) % n] = nums[i];
        nums = move(cpy);
#endif
    }
};