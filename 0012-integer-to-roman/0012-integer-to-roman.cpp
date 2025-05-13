class Solution {
public:
    string intToRoman(int num) {
        const vector<pair<char, int>> values = {
            {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50},
            {'X', 10},   {'V', 5},   {'I', 1},   {'.', 0},
        };

        string answer{};
        for (int i = 0; i < values.size() - 1; ++i) {
            const auto& [cur_c, cur_d] = values[i];
            const auto& [next_c, next_d] = values[i + 1];
            if (i > 0) {
                const auto& [prev_c, prev_d] = values[i - 1];
                if (num >= 4 * cur_d) {
                    num -= 4 * cur_d;
                    answer += cur_c;
                    answer += prev_c;
                }
                if (i % 2 == 1 && num - cur_d >= 4 * next_d) {
                    num -= cur_d + 4 * next_d;
                    answer += next_c;
                    answer += prev_c;
                }
            }
            while (num >= cur_d) {
                num -= cur_d;
                answer += cur_c;
            }
        }
        return answer;
    }
};