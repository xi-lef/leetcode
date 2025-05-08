class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer{{1}};
        for (int i = 1; i < numRows; ++i) {
            auto& cur = answer.emplace_back(i + 1);
            const auto& prev = answer[i - 1];

            cur[0] = cur[i] = 1;
            for (int j = 1; j < i + 0; ++j) {
                cur[j] = prev[j - 1] + prev[j];
            }
        }
        return answer;
    }
};