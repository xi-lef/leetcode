class Solution {
public:
    string makeFancyString(const string& s) {
        string answer{s[0]};
        int consecutive = 1;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == answer.back())
                ++consecutive;
            else
                consecutive = 1;

            if (consecutive < 3)
                answer.push_back(s[i]);
        }
        return answer;
    }
};