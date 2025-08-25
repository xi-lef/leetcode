class Solution {
public:
    vector<int> findDiagonalOrder(const vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();

        int x = 0;
        int y = 0;
        bool dir_up_right = true;
        vector<int> answer{};
        while (answer.size() != n * m) {
            answer.push_back(mat[y][x]);
            if (dir_up_right) {
                if (x == n - 1) {
                    ++y;
                    dir_up_right = false;
                } else if (y == 0) {
                    ++x;
                    dir_up_right = false;
                } else { // default case
                    ++x;
                    --y;
                }
            } else {
                if (y == m - 1) {
                    ++x;
                    dir_up_right = true;
                } else if (x == 0) {
                    ++y;
                    dir_up_right = true;
                } else { // default case
                    --x;
                    ++y;
                }
            }
        }
        return answer;
    }
};