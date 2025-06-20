class Solution {
public:
    int maxDistance(const string& s, int k) {
        int x = 0;
        int y = 0;
        array<int, 128> count{};
        int best = 0;
        for (const char& c : s) {
            y += c == 'N';
            y -= c == 'S';
            x += c == 'E';
            x -= c == 'W';
            ++count[c];

            int dist = abs(x) + abs(y);
            if (x == 0)
                dist += 2 * min(k, count[y > 0 ? 'S' : 'N'] +
                                       min(count['W'], count['E']));
            else if (y == 0)
                dist += 2 * min(k, min(count['S'], count['N']) +
                                       count[x > 0 ? 'W' : 'E']);
            else
                dist += 2 * min(k, count[x > 0 ? 'W' : 'E'] +
                                       count[y > 0 ? 'S' : 'N']);
            best = max(best, dist);
        }
        return best;
    }
};