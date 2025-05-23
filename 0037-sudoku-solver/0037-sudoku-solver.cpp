class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int y = 0; y < 9; ++y) {
            for (int x = 0; x < 9; ++x) {
                const char c = board[y][x];
                if (c != '.') {
                    rows[y][c - '1'] = true;
                    cols[x][c - '1'] = true;
                    boxes[box_index(x, y)][c - '1'] = true;
                }
            }
        }
        solve(board);
    }

private:
    vector<vector<bool>> rows{9, vector<bool>(9)};
    vector<vector<bool>> cols{9, vector<bool>(9)};
    vector<vector<bool>> boxes{9, vector<bool>(9)};

    int box_index(int x, int y) { return y / 3 * 3 + x / 3; }

    bool solve(vector<vector<char>>& board, int point = 0) {
        while (point < 81 && board[point / 9][point % 9] != '.')
            ++point;
        if (point == 81)
            return true;

        const int x = point % 9;
        const int y = point / 9;
        const int bi = box_index(x, y);
        for (int i = 0; i < 9; ++i) {
            if (rows[y][i] || cols[x][i] || boxes[bi][i])
                continue;

            board[y][x] = i + '1';
            rows[y][i] = cols[x][i] = boxes[bi][i] = true;
            if (solve(board, point + 1))
                return true;
            rows[y][i] = cols[x][i] = boxes[bi][i] = false;
        }
        board[y][x] = '.';
        return false;
    }
};