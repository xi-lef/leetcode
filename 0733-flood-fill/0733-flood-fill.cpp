class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        const int replace = image[sr][sc];
        if (replace == color)
            return image;

        vector<pair<int, int>> stack{{sr, sc}};
        while (!stack.empty()) {
            const auto [r, c] = stack.back();
            stack.pop_back();

            if (image[r][c] != replace)
                continue;
            image[r][c] = color;

            for (const auto& [dr, dc] :
                 {pair{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                const int nr = r + dr;
                const int nc = c + dc;
                if (nr < 0 || nr >= image.size() || nc < 0 ||
                    nc >= image[0].size())
                    continue;
                stack.push_back({nr, nc});
            }
        }
        return image;
    }
};