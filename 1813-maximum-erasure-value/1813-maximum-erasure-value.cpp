class Solution {
public:
    int maximumUniqueSubarray(const vector<int>& nums) {
#if 1
        vector<bool> subarray(10001);
        int best = 0;
        int cur_sum = 0;
        int a = 0;
        int b = 0;
        while (b < nums.size()) {
            const int num = nums[b];
            if (subarray[num]) {
                while (nums[a] != num) {
                    cur_sum -= nums[a];
                    subarray[nums[a++]] = false;
                }
                // don't remove nums[a] (i.e., num) so we can skip the else-case
                // (which would insert it again)
                ++a;
            } else {
                subarray[num] = true;
                cur_sum += num;
                best = max(best, cur_sum);
            }
            ++b;
        }
        return best;
#else
        unordered_set<int> subarray{};
        int best = 0;
        int cur_sum = 0;
        int a = 0;
        int b = 0;
        while (b < nums.size()) {
            const int num = nums[b];
            if (subarray.contains(num)) {
                while (nums[a] != num) {
                    cur_sum -= nums[a];
                    subarray.erase(nums[a++]);
                }
                // don't remove nums[a] (i.e., num) so we can skip the else-case
                // (which would insert it again)
                ++a;
            } else {
                subarray.insert(num);
                cur_sum += num;
                best = max(best, cur_sum);
            }
            ++b;
        }
        return best;
#endif
    }
};