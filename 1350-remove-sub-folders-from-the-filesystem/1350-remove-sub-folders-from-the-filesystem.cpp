class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        ranges::sort(folder);
        vector<string> answer{folder[0]};
        int cur = 0;
        for (int i = 1; i < folder.size(); ++i) {
            const string& s = folder[i];
            if (!(s.starts_with(folder[cur]) && s[folder[cur].size()] == '/')) {
                answer.push_back(s);
                cur = i;
            }
        }
        return answer;
    }
};