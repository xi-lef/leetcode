class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const size_t n = nums.size();
        ranges::sort(nums);

        vector<vector<int>> answer{};
        for (size_t i = 0; i < n;) {
            const int a = nums[i];
            if (a >= 0 && a > target)
                break;
            for (size_t h = i + 1; h < n;) {
                const int b = nums[h];
                if (b >= 0 && a + b > target)
                    break;

                size_t j = h + 1;
                size_t k = n - 1;
                while (j < k) {
                    const int c = nums[j];
                    const int d = nums[k];
                    const long sum = long{a} + b + c + d;
                    if (sum == target)
                        answer.emplace_back(initializer_list{a, b, c, d});
                    if (sum <= target) {
                        while (++j < n && nums[j] == c)
                            ;
                    } else if (sum > target) {
                        while (--k > h && nums[k] == d)
                            ;
                    }
                }

                while (++h < n && (nums[h] == b || nums[h] == a))
                    ;
            }
            while (++i < n && nums[i] == a)
                ;
        }

        return answer;
    }
};