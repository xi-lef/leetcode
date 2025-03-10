class Solution {
public:
    vector<vector<int>> updateMatrix(const vector<vector<int>>& mat) {
        const size_t max_y = mat.size();
        const size_t max_x = mat[0].size();
        deque<tuple<int, int, int>> stack;
        vector<vector<int>> result(max_y, vector(max_x, 100'000));
        for (size_t y = 0; y < max_y; ++y) {
            for (size_t x = 0; x < max_x; ++x) {
                if (mat[y][x] == 0) {
                    stack.emplace_back(y, x, 0);
                }
            }
        }

        while (!stack.empty()) {
            const auto [y, x, dist] = stack.front();
            stack.pop_front();

            if (result[y][x] <= dist) {
                continue;
            }
            result[y][x] = dist;

            for (const auto& [dy, dx] :
                 {pair{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                const int ny = y + dy;
                const int nx = x + dx;
                const auto np = pair{ny, nx};
                if (ny >= 0 && ny < max_y && nx >= 0 && nx < max_x &&
                    mat[ny][nx] != 0 && result[ny][nx] > dist + 1) {
                    stack.emplace_back(ny, nx, dist + 1);
                }
            }
        }
        return result;
    }
};
