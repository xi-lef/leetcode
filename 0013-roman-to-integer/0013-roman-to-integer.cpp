class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values = {{'I', 1},   {'V', 5},   {'X', 10},
                                           {'L', 50},  {'C', 100}, {'D', 500},
                                           {'M', 1000}};
        int answer = values[s[0]];
        for (size_t i = 1; i < s.size(); ++i) {
            const int prev = values[s[i - 1]];
            const int cur = values[s[i]];
            if (i > 0 && prev < cur) {
                answer -= 2 * prev;
            }
            answer += cur;
        }
        return answer;
    }
};