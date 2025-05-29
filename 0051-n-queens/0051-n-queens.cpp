class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        rows = vector<bool>(n);
        cols = vector<bool>(n);
        diag_up = vector<bool>(n * 2 - 1);
        diag_down = vector<bool>(n * 2 - 1);
        vector<string> board(n, string(n, '.'));
        solve(n, board);
        return answer;
    }

private:
    vector<vector<string>> answer{};

    vector<bool> rows;
    vector<bool> cols;
    vector<bool> diag_up;
    vector<bool> diag_down;

    void solve(int n, vector<string>& board, int queens = 0, int y = 0) {
        for (int x = 0; x < n; ++x) {
            const int up_i = x + y;
            const int down_i = x + (n - 1 - y);
            if (cols[x] || diag_up[up_i] || diag_down[down_i])
                continue;

            board[y][x] = 'Q';
            if (++queens == n) {
                answer.push_back(board);
            } else {
                rows[y] = cols[x] = diag_up[up_i] = diag_down[down_i] = true;
                solve(n, board, queens, y + 1);
                rows[y] = cols[x] = diag_up[up_i] = diag_down[down_i] = false;
            }
            --queens;
            board[y][x] = '.';
        }
    }
};