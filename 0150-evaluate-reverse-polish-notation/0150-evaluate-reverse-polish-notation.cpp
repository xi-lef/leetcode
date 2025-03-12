class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (const string& t : tokens) {
            if ("+-*/"sv.contains(t)) {
                const int b = s.top();
                s.pop();
                const int a = s.top();
                s.pop();
                const char op = t[0];
                const int c = op == '+'   ? a + b
                              : op == '-' ? a - b
                              : op == '*' ? a * b
                                          : a / b;
                s.push(c);
            } else {
                s.push(stol(t));
            }
        }
        return s.top();
    }
};