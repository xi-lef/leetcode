class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        const int inc = (numRows - 1) * 2;
        string answer{};
        for (int i = 0; i < numRows; ++i) {
            for (int cur = 0; cur + i < s.size(); cur += inc) {
                answer.push_back(s[cur + i]);
                const int second = cur + inc - i;
                if (i && i != numRows - 1 && second < s.size())
                    answer.push_back(s[second]);
            }
        }
        return answer;
    }
};