class Solution {
public:
    bool canPartition(vector<int>& nums) {
        const int total = *ranges::fold_left_first(nums, plus{});
        if (total % 2)
            return false;
        const int target = total / 2;

#if 0
        unordered_set<int> sums{};
        for (const int &n : nums) {
            if (n == target)
                return true;
            unordered_set<int> bla{n};
            for (const int &s : sums) {
                const int t = s + n;
                if (t == target)
                    return true;
                else if (t < target)
                    bla.insert(t);
            }
            sums.merge(move(bla));
        }
#else
        vector<bool> part(target + 1, false);
        part[0] = true;
        for (const int& n : nums) {
            for (int i = target; i >= n; --i) {
                if (part[i - n]) {
                    if (i == target)
                        return true;
                    part[i] = true;
                }
            }
        }
#endif
        return false;
    }
};