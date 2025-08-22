class Solution {
public:
    int minimumArea(const vector<vector<int>>& grid) {
        const int m = grid.size();
        const int n = grid[0].size();

        int min_x = n;
        int max_x = 0;
        int min_y = m;
        int max_y = 0;
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (grid[y][x] == 1) {
                    min_x = min(min_x, x);
                    max_x = max(max_x, x);
                    min_y = min(min_y, y);
                    max_y = max(max_y, y);
                }
            }
        }
        return (max_x - min_x + 1) * (max_y - min_y + 1);
    }
};