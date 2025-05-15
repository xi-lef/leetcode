class Solution {
public:
    vector<string> getLongestSubsequence(const vector<string>& words,
                                         const vector<int>& groups) {
        vector<string> answer{};
        int cur = groups[0];
        for (size_t i = 0; i < groups.size(); ++i) {
            if (groups[i] == cur) {
                answer.push_back(words[i]);
                cur = !cur;
            }
        }
        return answer;
    }
};