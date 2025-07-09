class Solution {
public:
    int maxFreeTime(int eventTime, int k, const vector<int>& startTime,
                    const vector<int>& endTime) {
        const int n = startTime.size();
        int cur_sum = 0;
        int best_sum = 0;
        for (int i = 0; i < n + 1; ++i) {
            if (i >= k + 1)
                cur_sum -= startTime[i - k - 1] -
                           (i == k + 1 ? 0 : endTime[i - k - 2]);
            cur_sum += (i == n ? eventTime : startTime[i]) -
                       (i == 0 ? 0 : endTime[i - 1]);
            best_sum = max(best_sum, cur_sum);
        }
        return best_sum;
    }
};