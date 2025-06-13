class Solution {
public:
    int findTargetSumWays(const vector<int>& nums, int target) {
        vector<int> reachable(2001);
        reachable[1000] = 1;
        int total = 0;
        for (const int& num : nums) {
            vector<int> tmp(reachable.size());
            for (int i = 1000 - total; i <= 1000 + total; ++i) {
                const auto& r = reachable[i];
                tmp[i - num] += r;
                tmp[i + num] += r;
            }
            total += num;
            reachable = move(tmp);
        }
        return reachable[1000 + target];
    }
};