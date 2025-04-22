class Solution {
public:
    int lengthOfLastWord(const string& s) {
        int answer = 0;
        bool start = true;
        for (const char& c : s) {
            if (c == ' ') {
                start = true;
            } else {
                if (start) {
                    answer = 0;
                    start = false;
                }
                ++answer;
            }
        }
        return answer;
    }
};