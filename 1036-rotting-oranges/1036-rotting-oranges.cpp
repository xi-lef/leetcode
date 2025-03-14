class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        const int max_y = grid.size();
        const int max_x = grid[0].size();
        int fresh = 0;
        vector<pair<int, int>> rotten{};
        for (int y = 0; y < max_y; ++y) {
            for (int x = 0; x < max_x; ++x) {
                const int o = grid[y][x];
                if (o == 1)
                    ++fresh;
                else if (o == 2)
                    rotten.emplace_back(y, x);
            }
        }

        int minutes = 0;
        while (fresh) {
            vector<pair<int, int>> next_rotten{};
            while (!rotten.empty()) {
                const auto [ry, rx] = rotten.back();
                rotten.pop_back();

                for (const auto& [dy, dx] :
                     {pair{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                    const int ny = ry + dy;
                    const int nx = rx + dx;
                    if (ny >= 0 && ny < max_y && nx >= 0 && nx < max_x &&
                        grid[ny][nx] == 1) {
                        grid[ny][nx] = 2;
                        --fresh;
                        next_rotten.emplace_back(ny, nx);
                    }
                }
            }

            if (next_rotten.empty())
                return -1;
            ++minutes;
            rotten = move(next_rotten);
        }
        return minutes;
    }
};