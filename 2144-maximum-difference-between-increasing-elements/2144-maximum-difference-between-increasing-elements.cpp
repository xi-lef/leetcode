class Solution {
public:
    int maximumDifference(const vector<int>& nums) {
        int mi = INT_MAX;
        int ma = INT_MIN;
        int best = -1;
        for (const int& num : nums) {
            if (num < mi)
                mi = ma = num;
            ma = max(ma, num);
            if (ma != mi)
                best = max(best, ma - mi);
        }
        return best;
    }
};