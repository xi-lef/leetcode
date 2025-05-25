class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        const int n = nums.size();
        vector<string> answer{};
        for (int i = 0; i < n;) {
            const int start = nums[i];
            int j = i + 1;
            while (j < n && nums[j] == start + (j - i))
                ++j;

            if (j == i + 1)
                answer.push_back(to_string(start));
            else
                answer.push_back(format("{}->{}", start, nums[j - 1]));
            i = j;
        }
        return answer;
    }
};