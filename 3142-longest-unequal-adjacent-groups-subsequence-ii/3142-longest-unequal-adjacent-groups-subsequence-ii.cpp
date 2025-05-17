class Solution {
public:
    vector<string> getWordsInLongestSubsequence(const vector<string>& words,
                                                const vector<int>& groups) {
        const int n = words.size();

        vector<int> dp(n);
        vector<int> prev(n, -1);
        int best = 0;
        int best_i = 0;
        for (int i = 0; i < n; ++i) {
            const string& word = words[i];
            const int& group = groups[i];
            int m = 0;
            int m_j = -1;
            for (int j = 0; j < i; ++j) {
                const string& w = words[j];
                if (dp[j] > m && groups[j] != group &&
                    w.size() == word.size()) {
                    int ham = 0;
                    for (int k = 0; k < w.size() && ham <= 1; ++k)
                        ham += w[k] != word[k];
                    if (ham == 1) {
                        m = dp[j];
                        m_j = j;
                    }
                }
            }
            dp[i] = m + 1;
            prev[i] = m_j;
            if (dp[i] > best) {
                best = dp[i];
                best_i = i;
            }
        }

        vector<string> answer{};
        while (best_i != -1) {
            answer.push_back(words[best_i]);
            best_i = prev[best_i];
        }
        ranges::reverse(answer);
        return answer;
    }
};