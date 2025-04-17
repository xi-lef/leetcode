class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer{};
        string s{};
        backtrack(n, 0, s, answer);
        return answer;
    }

    void backtrack(int n, int rem, string& s, vector<string>& answer) {
        if (n == 0 && rem == 0) {
            answer.push_back(s);
            return;
        }
        if (n > 0) {
            s.push_back('(');
            backtrack(n - 1, rem + 1, s, answer);
            s.pop_back();
        }
        if (rem > 0) {
            s.push_back(')');
            backtrack(n, rem - 1, s, answer);
            s.pop_back();
        }
    }
};