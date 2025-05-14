class Solution {
public:
    int lengthAfterTransformations(const string& s, int t) {
        constexpr long mod = long(1e9) + 7;

#if 1 // simple
        vector<long> count(26);
        for (const char& c : s)
            ++count[c - 'a'];

#if 1 // simple-best
        int last = 25;
        for (int i = 0; i < t; ++i) {
            (count[(last + 1) % 26] += count[last]) %= mod;
            if (last-- == 0)
                last = 25;
        }
#else // simple-ok
        for (int i = 0; i < t; ++i) {
            const int last = count[25];
            for (int j = 25; j > 0; --j)
                count[j] = count[j - 1];
            count[0] = last;
            (count[1] += last) %= mod;
        }
#endif
        int total = 0;
        for (const auto& n : count)
            (total += n) %= mod;
        return total;

#else // bad
        unordered_map<char, long> a_count{{'a', 1}};
        int rem = t;
        while (rem > 0) {
            decltype(a_count) next{};
            if (rem >= 26) {
                for (const auto& [c, n] : a_count) {
                    (next[c] += n) %= mod;
                    if (c == 'z') {
                        (next['a'] += n) %= mod;
                        (next['b'] += n) %= mod;
                    } else {
                        (next[c + 1] += n) %= mod;
                    }
                }
                rem -= 26;
            } else {
                for (const auto& [c, n] : a_count) {
                    if (c + rem <= 'z') {
                        next[c + rem] += n;
                    } else {
                        next[(c - 'a' + rem) % 26 + 'a'] += n;
                        next[(c - 'a' + rem) % 26 + 'a' + 1] += n;
                    }
                }
                rem = 0;
            }
            a_count = move(next);
        }

        unordered_map<char, long> count{};
        for (const char& c : s)
            ++count[c];

        long total = 0;
        for (const auto& [c, n] : count) {
            auto copy = a_count;
            for (int i = 0; i < c - 'a'; ++i) {
                decltype(copy) next{};
                for (const auto& [c, n] : copy) {
                    if (c == 'z') {
                        (next['a'] += n) %= mod;
                        (next['b'] += n) %= mod;
                    } else {
                        (next[c + 1] += n) %= mod;
                    }
                }
                copy = move(next);
            }
            for (const auto& [_, m] : copy)
                (total += n * m) %= mod;
        }

        return total;
#endif
    }
};