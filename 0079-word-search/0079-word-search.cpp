class Solution {
public:
    int max_y;
    int max_x;
    bool exist(vector<vector<char>>& board, string word) {
        max_y = board.size();
        max_x = board[0].size();

        vector<pair<int, int>> forward{};
        vector<pair<int, int>> backward{};
        for (int y = 0; y < max_y; ++y) {
            for (int x = 0; x < max_x; ++x) {
                if (board[y][x] == word[0])
                    forward.emplace_back(y, x);
                if (board[y][x] == word[word.size() - 1])
                    backward.emplace_back(y, x);
            }
        }

        const bool f = forward.size() < backward.size();
        const auto& points = f ? forward : backward;
        if (!f)
            ranges::reverse(word);
        for (const auto& [y, x] : points) {
            if (solve(board, word, y, x, 1))
                return true;
        }

        return false;
    }

    bool solve(vector<vector<char>>& board, string word, int y, int x,
               int pos) {
        if (pos == word.size())
            return true;
        const char save = board[y][x];
        board[y][x] = 0;

        for (const auto& [dy, dx] : {pair{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
            const int ny = y + dy;
            const int nx = x + dx;
            if (ny >= 0 && ny < max_y && nx >= 0 && nx < max_x &&
                board[ny][nx] == word[pos]) {
                if (solve(board, word, ny, nx, pos + 1))
                    return true;
            }
        }

        board[y][x] = save;
        return false;
    }
};