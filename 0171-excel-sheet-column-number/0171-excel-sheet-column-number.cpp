class Solution {
public:
    int titleToNumber(const string& columnTitle) {
        int answer = 0;
        for (const char& c : columnTitle) {
            answer *= 26;
            answer += c - 'A' + 1;
        }
        return answer;
    }
};