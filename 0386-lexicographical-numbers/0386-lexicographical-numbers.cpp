class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> answer{};
#if 1
        int i = 1;
        while (answer.size() < n) {
            answer.push_back(i);
            if (i * 10 <= n) {
                i *= 10;
            } else {
                while (i == n || i % 10 == 9)
                    i /= 10;
                ++i;
            }
        }
#else
        solve(answer, n, 0, true);
#endif
        return answer;
    }

private:
    void solve(vector<int>& answer, int n, int i, bool increment) {
        if (i > n)
            return;

        if (i != 0) {
            answer.push_back(i);
            solve(answer, n, i * 10, true);
        }
        if (increment)
            for (int d = 1; d <= 9; ++d)
                solve(answer, n, i + d, false);
    }
};