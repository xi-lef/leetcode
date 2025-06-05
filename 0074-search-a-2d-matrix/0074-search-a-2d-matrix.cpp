class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        const int n = matrix[0].size();

        int l = 0;
        int h = m * n;
        while (l < h) {
            const int mid = l + (h - l) / 2;
            const int v = matrix[mid / n][mid % n];

            if (v == target) {
                return true;
            } else if (v < target) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return false;
    }
};