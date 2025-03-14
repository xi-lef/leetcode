class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int max_y = grid.size();
        const int max_x = grid[0].size();
        int islands = 0;
        for (int y = 0; y < max_y; ++y) {
            for (int x = 0; x < max_x; ++x) {
                if (grid[y][x] == '0')
                    continue;
                grid[y][x] = '0';
                ++islands;

                vector<pair<int, int>> dfs{pair{y, x}};
                while (!dfs.empty()) {
                    const auto [y, x] = dfs.back();
                    dfs.pop_back();

                    for (const auto& [dy, dx] :
                         {pair{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                        const int ny = y + dy;
                        const int nx = x + dx;
                        if (ny >= 0 && ny < max_y && nx >= 0 && nx < max_x &&
                            grid[ny][nx] == '1') {
                            grid[ny][nx] = '0';
                            dfs.emplace_back(y + dy, x + dx);
                        }
                    }
                }
            }
        }
        return islands;
    }
};