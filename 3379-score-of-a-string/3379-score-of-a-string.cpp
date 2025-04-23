class Solution {
public:
    int scoreOfString(const string& s) {
        int answer = 0;
        for (size_t i = 1; i < s.size(); ++i) {
            answer += abs(s[i] - s[i - 1]);
        }
        return answer;
    }
};