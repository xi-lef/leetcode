class Solution {
public:
    string smallestEquivalentString(const string& s1, const string& s2,
                                    const string& baseStr) {
        vector<char> uf(128);
        for (char i = 0; i < uf.size(); ++i)
            uf[i] = i;

        const auto find = [&](this auto self, char i) {
            if (uf[i] == i)
                return i;
            return uf[i] = self(uf[i]);
        };

        const auto unite = [&](char a, char b) {
            a = find(a);
            b = find(b);
            if (a != b)
                uf[a] = uf[b] = min(a, b);
        };

        for (int i = 0; i < s1.size(); ++i)
            unite(s1[i], s2[i]);

        string answer{baseStr};
        for (char& c : answer)
            c = find(c);
        return answer;
    }
};