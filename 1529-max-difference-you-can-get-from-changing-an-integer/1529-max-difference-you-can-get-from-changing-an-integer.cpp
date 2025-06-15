class Solution {
public:
    int maxDiff(int num) {
        string smin = to_string(num);
        string smax{smin};

        if (const size_t pos = smin.find_first_not_of("01");
            pos != string::npos)
            ranges::replace(smin, char{smin[pos]}, pos == 0 ? '1' : '0');
        if (const size_t pos = smax.find_first_not_of('9'); pos != string::npos)
            ranges::replace(smax, char{smax[pos]}, '9');

        return stol(smax) - stol(smin);
    }
};