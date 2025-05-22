class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();

        const bool zero_row0 = ranges::contains(matrix[0], 0);
        for (int y = 1; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (matrix[y][x] == 0)
                    matrix[0][x] = matrix[y][0] = 0;
            }
        }

        for (int y = 1; y < m; ++y) {
            for (int x = n - 1; x >= 0; --x) {
                if (matrix[0][x] == 0 || matrix[y][0] == 0)
                    matrix[y][x] = 0;
            }
        }
        if (zero_row0)
            ranges::fill(matrix[0], 0);
    }
};