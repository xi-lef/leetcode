class Solution {
public:
    int possibleStringCount(const string& word) {
        int answer = 1;
        for (int i = 1; i < word.size(); ++i) {
            if (word[i - 1] == word[i])
                ++answer;
        }
        return answer;
    }
};