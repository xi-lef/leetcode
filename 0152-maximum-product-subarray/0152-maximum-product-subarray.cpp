class Solution {
public:
    int maxProduct(const vector<int>& nums) {
        int best = INT_MIN;
        int take = 1;
        int not_take = 0;
        for (const int& num : nums) {
            best = max(best, num);
            if (num == 0) {
                take = 1;
                not_take = 0;
                continue;
            }

            take *= num;
            if (not_take == 0 && num < 0) {
                not_take = 1;
            } else {
                not_take *= num;
                best = max(best, not_take);
            }
            best = max(best, take);
        }
        return best;
    }
};