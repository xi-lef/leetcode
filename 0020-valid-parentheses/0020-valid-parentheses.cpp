class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (const char &c : s) {
            if (c == ')' || c == '}' || c == ']') {
                if (stack.empty()
                    || stack.back() != (c == ')' ? '(' : c == '}' ? '{' : '[')) {
                    return false;
                }
                stack.pop_back();
            } else {
                stack.push_back(c);
            }
        }
        return stack.empty();
    }
};
