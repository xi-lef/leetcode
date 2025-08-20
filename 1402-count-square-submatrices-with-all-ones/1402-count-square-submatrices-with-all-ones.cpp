class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();

        int answer = 0;
        for (int i = 0; i < m; ++i)
            answer += matrix[i][0];
        for (int i = 1; i < n; ++i) // 1 so matrix[0][0] doesn't count twice
            answer += matrix[0][i];

        for (int y = 1; y < m; ++y) {
            for (int x = 1; x < n; ++x) {
                if (int& m = matrix[y][x]) {
                    const int top_left = matrix[y - 1][x - 1];
                    const int top = matrix[y - 1][x];
                    const int left = matrix[y][x - 1];
                    m = min({top_left, top, left}) + 1;
                    answer += m;
                }
            }
        }

        return answer;
    }
};