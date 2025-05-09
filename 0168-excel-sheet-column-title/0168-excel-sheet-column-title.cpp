class Solution {
public:
    string convertToTitle(int columnNumber) {
        string answer{};
        while (columnNumber-- > 0) {
            const char c = 'A' + columnNumber % 26;
            answer = c + answer;
            columnNumber /= 26;
        }
        return answer;
    }
};