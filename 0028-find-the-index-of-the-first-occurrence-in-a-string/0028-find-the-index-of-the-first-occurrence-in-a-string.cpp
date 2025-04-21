class Solution {
public:
    int strStr(const string& haystack, const string& needle) {
        const string_view sv{haystack};
        for (size_t i = 0; i < sv.size(); ++i) {
            if (sv.substr(i).starts_with(needle))
                return i;
        }
        return -1;
    }
};