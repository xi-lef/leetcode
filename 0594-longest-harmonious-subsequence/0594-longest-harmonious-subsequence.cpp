class Solution {
public:
    int findLHS(vector<int>& nums) {
#if 0
        map<int, int> count{};
        for (const int& num : nums) {
            ++count[num];
        }
        int last = INT_MIN;
        int last_count = 0;
        int best = 0;
        for (const auto& [k, v] : count) {
            if (k == last + 1)
                best = max(best, last_count + v);

            last = k;
            last_count = v;
        }
        return best;
#else
        ranges::sort(nums);

        int start = nums[0] - 2;
        int a_length = 0;
        int b_length = 0;
        int answer = 0;
        for (const int& num : nums) {
            if (num == start + 2 && b_length > 0) {
                ++start;
                a_length = b_length;
                b_length = 0;
            } else if (num > start + 1) {
                start = num;
                a_length = b_length = 0;
            }

            if (num == start) {
                ++a_length;
            } else { // num == start + 1
                ++b_length;
                answer = max(answer, a_length + b_length);
            }
        }
        return answer;
#endif
    }
};