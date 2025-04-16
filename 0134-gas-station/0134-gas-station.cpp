class Solution {
public:
    int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) {
        if (ranges::fold_left(cost, 0, plus{}) >
            ranges::fold_left(gas, 0, plus{}))
            return -1;

        const int n = gas.size();
        int best_start = -1;
        int best_end = -1;
        int best_rem = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (i == best_end)
                break;

            int pos = i;
            int tank = gas[i];
            bool best = false;
            while (tank >= cost[pos]) {
                tank -= cost[pos];
                ++pos %= n;
                if (pos == i) {
                    return i;
                }
                if (pos == best_start) {
                    pos = best_end;
                    tank += best_rem;
                    best = true;
                } else {
                    tank += gas[pos];
                }
            }
            if (best || best_start == -1) {
                best_start = i;
                best_end = pos;
                best_rem = tank;
            }
        }
        return -1;
    }
};