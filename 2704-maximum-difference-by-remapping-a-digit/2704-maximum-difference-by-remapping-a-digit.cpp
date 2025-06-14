class Solution {
public:
    int minMaxDifference(int num) {
        const string s = to_string(num);

        const char replace_min = s[0];
        string smin{s};
        for (char& c : smin)
            if (c == replace_min)
                c = '0';

        string smax{s};
        if (const size_t pos = s.find_first_not_of('9'); pos != string::npos) {
            const char replace_max = s[pos];
            for (char& c : smax)
                if (c == replace_max)
                    c = '9';
        }

        return stol(smax) - stol(smin);
    }
};