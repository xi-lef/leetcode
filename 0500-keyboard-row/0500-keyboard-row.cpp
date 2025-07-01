class Solution {
public:
    vector<string> findWords(const vector<string>& words) {
        const string row1 = "qwertyuiop";
        const string row2 = "asdfghjkl";
        const string row3 = "zxcvbnm";

        vector<string> answer{};
        for (const string& word : words) {
            for (const string& row : {row1, row2, row3}) {
                if (ranges::all_of(word, [&](const char& c) {
                        return row.contains(tolower(c));
                    })) {
                    answer.push_back(word);
                    break;
                }
            }
        }
        return answer;
    }
};