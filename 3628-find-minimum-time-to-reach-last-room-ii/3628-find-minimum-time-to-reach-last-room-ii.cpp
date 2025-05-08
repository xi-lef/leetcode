class Solution {
public:
    int minTimeToReach(const vector<vector<int>>& moveTime) {
        const int target_y = moveTime.size() - 1;
        const int target_x = moveTime[0].size() - 1;

        using T = tuple<int, int, int, bool>;
        const auto cmp = [](const T& l, const T& r) {
            return get<0>(l) > get<0>(r);
        };
        priority_queue<T, vector<T>, decltype(cmp)> q{};
        q.emplace(0, 0, 0, true);
        vector<vector<int>> seen(moveTime.size(),
                                 vector<int>(moveTime[0].size()));
        while (!q.empty()) {
            const auto [t, x, y, onesec] = q.top();
            q.pop();

            if (x == target_x && y == target_y)
                return t;

            for (const auto& [dx, dy] :
                 {pair{0, 1}, {0, -1}, {1, 0}, {-1, 0}}) {
                const int nx = x + dx;
                const int ny = y + dy;
                if (nx >= 0 && nx <= target_x && ny >= 0 && ny <= target_y) {
                    const int nt = max(moveTime[ny][nx], t) + 1 + !onesec;
                    int& ns = seen[ny][nx];
                    if (ns == 0 || ns > nt) {
                        ns = nt;
                        q.emplace(nt, nx, ny, !onesec);
                    }
                }
            }
        }
        return -1;
    }
};