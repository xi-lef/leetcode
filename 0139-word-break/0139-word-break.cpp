class Solution {
public:
    unordered_set<string> bad{};
    bool wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0)
            return true;
        if (bad.contains(s))
            return false;

        for (const string& word : wordDict) {
            if (s.starts_with(word)) {
                if (wordBreak(s.substr(word.size()), wordDict))
                    return true;
            }
        }
        bad.insert(s);
        return false;
    }
};