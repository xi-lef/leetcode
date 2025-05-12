class Solution {
public:
    int findCircleNum(const vector<vector<int>>& isConnected) {
        const int n = isConnected.size();

        vector<int> dsu(n);
        for (int i = 0; i < dsu.size(); ++i)
            dsu[i] = i;

        const auto find = [&](this const auto& self, int i) {
            if (i == dsu[i])
                return i;
            return dsu[i] = self(dsu[i]);
        };
        const auto make_union = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a != b) {
                dsu[b] = a;
            }
        };

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (isConnected[i][j])
                    make_union(i, j);
            }
        }

        int provinces = 0;
        for (int i = 0; i < n; ++i)
            provinces += dsu[i] == i;
        return provinces;
    }
};