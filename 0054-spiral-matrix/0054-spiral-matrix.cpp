class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int max_y = matrix.size() - 1;
        int max_x = matrix[0].size() - 1;
        int min_x = 0;
        int min_y = 0;

        vector<int> answer{};
        int cur_x = 0;
        int cur_y = 0;
        const pair<int, int> dirs[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int cur_dir = max_x == 0 ? 1 : 0;
        pair dir = dirs[cur_dir];
        while (min_x <= max_x && min_y <= max_y) {
            answer.push_back(matrix[cur_y][cur_x]);
            cur_x += dir.first;
            cur_y += dir.second;
            if (dir.first == -1 && cur_x <= min_x) {
                --max_y;
            } else if (dir.first == 1 && cur_x >= max_x) {
                ++min_y;
            } else if (dir.second == -1 && cur_y <= min_y) {
                ++min_x;
            } else if (dir.second == 1 && cur_y >= max_y) {
                --max_x;
            } else {
                continue;
            }
            dir = dirs[++cur_dir %= 4];
        }
        if (matrix.size() > 1 || matrix[0].size() > 1)
            answer.push_back(matrix[cur_y][cur_x]);
        return answer;
    }
};