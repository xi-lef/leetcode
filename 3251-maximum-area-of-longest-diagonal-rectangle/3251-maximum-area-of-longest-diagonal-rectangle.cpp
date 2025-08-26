class Solution {
public:
    int areaOfMaxDiagonal(const vector<vector<int>>& dimensions) {
        int best_diag = 0;
        int best_area = 0;
        for (const auto& dim : dimensions) {
            const int diag = dim[0] * dim[0] + dim[1] * dim[1];
            if (diag >= best_diag) {
                const int area = dim[0] * dim[1];
                if (diag == best_diag)
                    best_area = max(best_area, area);
                else
                    best_area = area;
                best_diag = diag;
            }
        }
        return best_area;
    }
};