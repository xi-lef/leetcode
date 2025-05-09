class Solution {
public:
    bool containsNearbyDuplicate(const vector<int>& nums, int k) {
        unordered_map<int, int> last{};
        for (int i = 0; i < nums.size(); ++i) {
            const int num = nums[i];
            if (last.contains(num) && i - last[num] <= k)
                return true;
            last[num] = i;
        }
        return false;
    }
};