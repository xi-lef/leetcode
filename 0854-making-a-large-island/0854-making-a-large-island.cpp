template <> struct hash<pair<int, int>> {
    size_t operator()(const pair<int, int>& p) const {
        return p.first * 501 + p.second;
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        const int n = grid.size();
#if 1
        vector<int> dsu(n * n);
        vector<int> size(n * n, 1);
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
                if (size[a] < size[b])
                    swap(a, b);
                dsu[b] = a;
                size[a] += size[b];
            }
        };
        const auto key = [&](int x, int y) { return y * n + x; };

        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] != 1)
                    continue;

                for (const auto& [dx, dy] :
                     {pair{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                    const int nx = x + dx;
                    const int ny = y + dy;
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    if (grid[nx][ny] == 1)
                        make_union(key(x, y), key(nx, ny));
                }
            }
        }

        int m = size[0];
        for (int x = 0; x < n; ++x) {
            for (int y = 0; y < n; ++y) {
                if (grid[x][y] != 0)
                    continue;

                int c = 1;
                unordered_set<int> seen{};
                for (const auto& [dx, dy] :
                     {pair{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                    const int nx = x + dx;
                    const int ny = y + dy;
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    if (grid[nx][ny] == 1) {
                        if (const int k = find(key(nx, ny));
                            !seen.contains(k)) {
                            seen.insert(k);
                            c += size[k];
                        }
                    }
                }
                m = max(m, c);
            }
        }
        return m;
#else
        using P = pair<int, int>;
        unordered_map<int, size_t> sizes{};
        int id = 2;

        for (size_t x = 0; x < n; ++x) {
            for (size_t y = 0; y < n; ++y) {
                if (grid[x][y] != 1)
                    continue;

                unordered_set<P> current;
                stack<P> work{{{x, y}}};
                while (!work.empty()) {
                    const P p = work.top();
                    work.pop();
                    const auto& [cx, cy] = p;

                    if (current.contains(p))
                        continue;
                    current.insert(p);
                    grid[cx][cy] = id;

                    for (const auto& [dx, dy] :
                         {pair{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                        const int nx = cx + dx;
                        const int ny = cy + dy;
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                            continue;
                        if (grid[nx][ny] != 0)
                            work.emplace(nx, ny);
                    }
                }
                sizes[id++] = current.size();
            }
        }

        size_t m = sizes[2];
        for (size_t x = 0; x < n; ++x) {
            for (size_t y = 0; y < n; ++y) {
                if (grid[x][y] != 0)
                    continue;

                size_t c = 1;
                unordered_set<int> ids;
                for (const auto& [dx, dy] :
                     {pair{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                    const int nx = x + dx;
                    const int ny = y + dy;
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    const int id = grid[nx][ny];
                    const size_t size = sizes[id];
                    if (size && !ids.contains(id)) {
                        ids.insert(id);
                        c += size;
                    }
                }
                m = max(m, c);
            }
        }
        return m;
#endif
    }
};