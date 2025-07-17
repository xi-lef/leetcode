class Solution {
public:
    vector<vector<int>> pacificAtlantic(const vector<vector<int>>& heights) {
        const int m = heights.size();
        const int n = heights[0].size();

        queue<pair<int, int>> bfs_pacific{};
        queue<pair<int, int>> bfs_atlantic{};
        for (int i = 0; i < n; ++i) {
            bfs_pacific.emplace(0, i);
            bfs_atlantic.emplace(m - 1, i);
        }
        for (int i = 0; i < m; ++i) {
            bfs_pacific.emplace(i, 0);
            bfs_atlantic.emplace(i, n - 1);
        }

        const auto do_bfs = [&](auto& bfs, auto& reach) {
            while (!bfs.empty()) {
                const auto [cy, cx] = bfs.front();
                bfs.pop();
                reach[cy][cx] = true;

                for (const auto& [dy, dx] :
                     {pair{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                    const int ny = cy + dy;
                    const int nx = cx + dx;
                    if (ny >= 0 && ny < m && nx >= 0 && nx < n &&
                        heights[ny][nx] >= heights[cy][cx] && !reach[ny][nx]) {
                        bfs.emplace(ny, nx);
                    }
                }
            }
        };
        vector<vector<bool>> reach_pacific(m, vector<bool>(n));
        vector<vector<bool>> reach_atlantic(m, vector<bool>(n));
        do_bfs(bfs_pacific, reach_pacific);
        do_bfs(bfs_atlantic, reach_atlantic);

        vector<vector<int>> answer{};
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (reach_pacific[y][x] && reach_atlantic[y][x])
                    answer.emplace_back(initializer_list{y, x});
            }
        }
        return answer;
    }
};