class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        ranges::sort(nums);
        long long answer = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            const int num = nums[i];
            if (num > 0 && num > upper)
                break;
            const auto start = nums.begin() + i + 1;
            const auto a = lower_bound(start, nums.end(), lower - num); 
            if (a == nums.end())
                continue;
            const auto b = upper_bound(a, nums.end(), upper - num);
            answer += distance(a, b);
        }
        return answer;
    }
};