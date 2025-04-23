class Solution {
public:
    string countAndSay(int n) {
        static unordered_map<int, string> dp{{1, "1"}};
        if (dp.contains(n))
            return dp[n];

        const string prev = countAndSay(n - 1);
        char cur = prev[0];
        size_t count = 0;
        string answer{};
        for (const char& c : prev) {
            if (c == cur) {
                ++count;
            } else {
                answer += to_string(count) + cur;
                cur = c;
                count = 1;
            }
        }
        answer += to_string(count) + cur;
        return dp[n] = answer;
    }
};