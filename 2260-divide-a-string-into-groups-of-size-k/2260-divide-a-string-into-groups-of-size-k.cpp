class Solution {
public:
    vector<string> divideString(const string& s, int k, char fill) {
        vector<string> answer{};
        for (int i = 0; i < s.size(); i += k) {
            string group = s.substr(i, k);
            group += string(k - group.size(), fill);
            answer.push_back(move(group));
        }
        return answer;
    }
};