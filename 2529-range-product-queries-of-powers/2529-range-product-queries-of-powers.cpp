class Solution {
public:
    vector<int> productQueries(int n, const vector<vector<int>>& queries) {
        vector<int> powers{};
        for (int x = n, p = 1; x; x /= 2, p *= 2) {
            if (x % 2)
                powers.push_back(p);
        }

        constexpr int mod = 1e9 + 7;
        const int m = powers.size();
        vector<vector<int>> products(m, vector<int>(m));
        for (int i = 0; i < m; ++i) {
            products[i][i] = powers[i];
            for (int j = i + 1; j < m; ++j)
                products[i][j] =
                    products[i][j - 1] * static_cast<long>(powers[j]) % mod;
        }

        vector<int> answers(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            const auto& q = queries[i];
            answers[i] = products[q.front()][q.back()];
        }
        return answers;
    }
};