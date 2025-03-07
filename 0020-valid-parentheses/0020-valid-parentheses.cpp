class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (const char &c : s) {
            if ("({["sv.contains(c)) {
                stack.push_back(c);
            } else {
                const unordered_map<char, char> mappings = {{')', '('}, {'}', '{'}, {']', '['}};
                if (stack.empty() || stack.back() != mappings.at(c)) {
                    return false;
                }
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};
