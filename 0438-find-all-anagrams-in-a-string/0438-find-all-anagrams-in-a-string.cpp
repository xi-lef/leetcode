class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        const int s_n = s.size();
        const int p_n = p.size();
        if (s_n < p_n)
            return {};

        array<int, 26> target{};
        for (const char& c : p)
            ++target[c - 'a'];
        array<int, 26> count{};
        for (int i = 0; i < p_n; ++i)
            ++count[s[i] - 'a'];

        vector<int> anagrams{};
        for (int i = 0; i < s_n - p_n + 1; ++i) {
            if (count == target)
                anagrams.push_back(i);

            --count[s[i] - 'a'];
            if (i + p_n < s_n)
                ++count[s[i + p_n] - 'a'];
        }
        return anagrams;
    }
};