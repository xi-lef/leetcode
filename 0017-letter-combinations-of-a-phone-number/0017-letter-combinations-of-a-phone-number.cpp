class Solution {
public:
    const unordered_map<char, vector<string>> buttons{
        {'2', {"a", "b", "c"}}, {'3', {"d", "e", "f"}},
        {'4', {"g", "h", "i"}}, {'5', {"j", "k", "l"}},
        {'6', {"m", "n", "o"}}, {'7', {"p", "q", "r", "s"}},
        {'8', {"t", "u", "v"}}, {'9', {"w", "x", "y", "z"}}};

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        const auto& button = buttons.at(digits[0]);
        if (digits.size() == 1)
            return button;

        vector<string> answer{};
        const auto sub = letterCombinations(digits.substr(1));
        for (const auto& c : button) {
            for (const string& s : sub) {
                answer.push_back(c + s);
            }
        }
        return answer;
    }
};