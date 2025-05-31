class Solution {
public:
    int snakesAndLadders(const vector<vector<int>>& board) {
        const int n = board.size();
        vector<int> rolls(n * n, INT_MAX);
        queue<pair<int, int>> todo{{{0, 0}}};

        while (!todo.empty()) {
            auto [i, cur] = todo.front();
            todo.pop();

            if (i == n * n - 1)
                return cur;
            ++cur;

            for (int d = 1; d <= 6 && i + d < rolls.size(); ++d) {
                const int p = i + d;
                const int y = p / n;
                const bool odd = y % 2 == 1;
                const int x = odd ? n - 1 - p % n : p % n;
                const int b = board[n - 1 - y][x];

                if (b == -1) {
                    if (cur < rolls[i + d]) {
                        rolls[i + d] = cur;
                        todo.emplace(i + d, cur);
                    }
                } else {
                    if (cur < rolls[b - 1]) {
                        rolls[b - 1] = cur;
                        todo.emplace(b - 1, cur);
                    }
                }
            }
        }
        return -1;
    }
};