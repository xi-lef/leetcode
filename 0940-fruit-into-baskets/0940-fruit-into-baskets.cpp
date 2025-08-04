class Solution {
public:
    int totalFruit(const vector<int>& fruits) {
        int a = -1;
        int b = -1;
        int a_count = 0;
        int b_count = 0;
        int last = -1;
        int in_a_row = 0;
        int best = 0;
        for (const int& fruit : fruits) {
            if (fruit == a) {
                ++a_count;
            } else if (fruit == b) {
                ++b_count;
            } else {
                a = last;
                if (a != -1)
                    a_count = in_a_row;

                b = fruit;
                b_count = 1;
            }
            best = max(best, a_count + b_count);

            if (fruit == last)
                ++in_a_row;
            else
                in_a_row = 1;
            last = fruit;
        }
        return best;
    }
};