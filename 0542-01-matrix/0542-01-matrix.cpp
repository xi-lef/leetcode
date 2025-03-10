class Solution {
public:
    vector<vector<int>> updateMatrix(const vector<vector<int>>& mat) {
        const size_t max_y = mat.size();
        const size_t max_x = mat[0].size();
        queue<pair<int, int>> stack;
        vector<vector<int>> result(max_y, vector(max_x, 100'000));
        for (size_t y = 0; y < max_y; ++y) {
            for (size_t x = 0; x < max_x; ++x) {
                if (mat[y][x] == 0) {
                    stack.emplace(y, x);
                    result[y][x] = 0;
                }
            }
        }

        while (!stack.empty()) {
            const auto [y, x] = stack.front();
            stack.pop();

            for (const auto& [dy, dx] :
                 {pair{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                const int ny = y + dy;
                const int nx = x + dx;
                if (ny >= 0 && ny < max_y && nx >= 0 && nx < max_x &&
                    mat[ny][nx] != 0 && result[ny][nx] > result[y][x] + 1) {
                    result[ny][nx] = result[y][x] + 1;
                    stack.emplace(ny, nx);
                }
            }
        }
        return result;
    }
};