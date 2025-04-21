class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> s{};
        for (int i = 0; i < nums.size(); ++i) {
            const int comp = target - nums[i];
            if (s.contains(comp))
                return {i, s[comp]};
            s[nums[i]] = i;
        }
        return {};
    }
};