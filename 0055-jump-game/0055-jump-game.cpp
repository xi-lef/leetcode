class Solution {
public:
    bool canJump(const vector<int>& nums) {
        if (nums.size() == 1)
            return true;

        vector<int> maxes(nums.size());
        int m = 0;
        for (int i = 0; i < nums.size(); ++i) {
            maxes[i] = m = max(m, nums[i]);
        }

        int pos = nums.size() - 1;
        while (pos > 0) {
            int next = pos;
            for (int i = max(0, pos - maxes[pos]); i < pos; ++i) {
                if (i + nums[i] >= pos) {
                    next = i;
                    break;
                }
            }
            if (next == pos)
                break;
            pos = next;
        }
        return pos == 0;
    }
};