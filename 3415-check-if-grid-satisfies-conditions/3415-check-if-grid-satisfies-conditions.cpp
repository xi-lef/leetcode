class Solution {
public:
    bool satisfiesConditions(const vector<vector<int>>& grid) {
        const int n = grid.size();
        const int m = grid[0].size();

        for (int x = 0; x < m; ++x) {
            for (int y = 1; y < n; ++y) {
                if (grid[y][x] != grid[y - 1][x])
                    return false;
            }
            if (x > 0 && grid[0][x] == grid[0][x - 1])
                return false;
        }
        return true;
    }
};