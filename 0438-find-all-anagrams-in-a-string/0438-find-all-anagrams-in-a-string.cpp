class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> target{};
        for (const char& c : p)
            ++target[c];

        unordered_map<char, int> count{};
        const int p_n = p.size();
        for (int i = 0; i < p_n; ++i)
            ++count[s[i]];

        const int s_n = s.size();
        vector<int> anagrams{};
        for (int i = 0; i < s_n - p_n + 1; ++i) {
            if (count == target)
                anagrams.push_back(i);
            if (--count[s[i]] == 0)
                count.erase(s[i]);
            if (i < s_n - p_n)
                ++count[s[i + p_n]];
        }
        return anagrams;
    }
};