class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const auto check = [](vector<bool>& exist, char c) {
            if (c != '.') {
                if (exist[c - '0'])
                    return true;
                exist[c - '0'] = true;
            }
            return false;
        };

        for (int i = 0; i < 9; ++i) {
            vector<bool> exist_r(9);
            vector<bool> exist_c(9);
            for (int j = 0; j < 9; ++j) {
                if (check(exist_r, board[i][j]) || check(exist_c, board[j][i]))
                    return false;
            }
        }

        for (int i = 0; i < 9; ++i) {
            vector<bool> exist(9);
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    if (check(exist, board[i / 3 * 3 + j][i % 3 * 3 + k]))
                        return false;
                }
            }
        }
        return true;
    }
};