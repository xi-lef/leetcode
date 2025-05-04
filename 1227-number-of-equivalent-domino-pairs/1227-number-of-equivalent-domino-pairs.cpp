class Solution {
public:
    int numEquivDominoPairs(const vector<vector<int>>& dominoes) {
        unordered_map<int, int> count{};
        int answer = 0;
        for (const auto& domino : dominoes) {
            const int mi = min(domino.front(), domino.back());
            const int ma = max(domino.front(), domino.back());
            answer += count[mi * 10 + ma]++;
        }
        return answer;
    }
};