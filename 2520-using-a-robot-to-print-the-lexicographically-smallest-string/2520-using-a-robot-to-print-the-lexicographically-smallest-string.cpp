class Solution {
public:
    string robotWithString(string& s) {
        vector<int> count(128);
        char lowest = 'z';
        for (const char& c : s) {
            ++count[c];
            lowest = min(lowest, c);
        }

        stack<char, vector<char>> st{};
        string answer{};
        for (const char& c : s) {
            st.push(c);
            --count[c];
            while (lowest <= 'z' && count[lowest] == 0)
                ++lowest;
            while (!st.empty() && (lowest > 'z' || lowest >= st.top())) {
                answer += st.top();
                st.pop();
            }
        }
        return answer;
    }
};