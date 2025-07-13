class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ranges::sort(g);
        ranges::sort(s);
        const int sn = s.size();

        int answer = 0;
        for (int g_i = 0, s_i = 0; g_i < g.size(); ++g_i, ++s_i) {
            while (s_i < sn && g[g_i] > s[s_i])
                ++s_i;
            if (s_i >= sn)
                break;
            ++answer;
        }
        return answer;
    }
};