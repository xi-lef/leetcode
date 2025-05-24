class Solution {
public:
    vector<int> findWordsContaining(const vector<string>& words, char x) {
        vector<int> answer{};
        for (int i = 0; i < words.size(); ++i) {
            for (const char& c : words[i]) {
                if (c == x) {
                    answer.push_back(i);
                    break;
                }
            }
        }
        return answer;
    }
};