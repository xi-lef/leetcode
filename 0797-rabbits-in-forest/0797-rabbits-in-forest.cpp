class Solution {
public:
    int numRabbits(const vector<int>& answers) {
        unordered_map<int, int> count{};
        for (const int& i : answers) {
            ++count[i];
        }
        int answer = 0;
        for (auto [k, v] : count) {
            // answer += ((v + k) / (k + 1)) * (k + 1);
            // answer += (k + 1) * (v / (k + 1) + bool(v % (k + 1)));
            while (v > 0) {
                answer += k + 1;
                v -= k + 1;
            }
        }
        return answer;
    }
};