class Solution {
public:
    int maxDifference(const string& s) {
        array<int, 26> counts{};
        for (const char& c : s)
            ++counts[c - 'a'];

        int freq_a1 = 0;
        int freq_a2 = 100;
        for (const int& count : counts) {
            if (count == 0)
                continue;
            if (count % 2 == 0 && count < freq_a2)
                freq_a2 = count;
            if (count % 2 == 1 && count > freq_a1)
                freq_a1 = count;
        }
        return freq_a1 - freq_a2;
    }
};