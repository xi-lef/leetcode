class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        ranges::sort(nums);
        const size_t n = nums.size();

        int best = INT_MAX;
        int answer = 0;
        for (int i = 0; i < n;) {
            const int a = nums[i];

            size_t j = i + 1;
            size_t k = n - 1;
            while (j < k) {
                const int b = nums[j];
                const int c = nums[k];
                const int sum = a + b + c;
                if (const int diff = abs(target - sum); diff < best) {
                    best = diff;
                    answer = sum;
                    if (answer == target)
                        return answer;
                }

                if (sum > target) {
                    while (--k > j && nums[k] == c)
                        ;
                } else {
                    while (++j < k && nums[j] == b)
                        ;
                }
            }

            if ((target > 0 && a > target) || (target < 0 && a >= 0))
                break;
            while (++i < n && nums[i] == a)
                ;
        }
        return answer;
    }
};