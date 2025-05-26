class Solution {
public:
    int numIdenticalPairs(const vector<int>& nums) {
        unordered_map<int, int> count{};
        for (const int& n : nums)
            ++count[n];
        int answer = 0;
        for (const auto& [_, c] : count)
            answer += (c - 1) * c / 2;
        return answer;
    }
};