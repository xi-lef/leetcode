class Solution {
public:
    int maximumGain(const string& s, int x, int y) {
        const auto good_op = x > y ? "ab" : "ba";
        const auto bad_op = x > y ? "ba" : "ab";
        const int good_points = max(x, y);
        const int bad_points = min(x, y);

        vector<int> st{};
        int answer = 0;
        for (int i = 0; i < s.size(); ++i) {
            const char c = s[i];
            if (!st.empty() && st.back() == good_op[0] && c == good_op[1]) {
                st.pop_back();
                answer += good_points;
            } else {
                st.push_back(c);
            }
        }

        for (vector<int> ts{}; !st.empty(); st.pop_back()) {
            if (!ts.empty() && st.back() == bad_op[0] &&
                ts.back() == bad_op[1]) {
                ts.pop_back();
                answer += bad_points;
            } else {
                ts.push_back(st.back());
            }
        }
        return answer;
    }
};