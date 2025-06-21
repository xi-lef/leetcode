class Solution {
public:
    int minimumDeletions(const string& word, int k) {
        array<int, 128> count{};
        for (const char& c : word)
            ++count[c];

        int best = word.size();
        for (char fixed = 'a'; fixed <= 'z'; ++fixed) {
            const int cou = count[fixed];
            if (cou == 0)
                continue;

            int rm = 0;
            for (char c = 'a'; c <= 'z'; ++c) {
                if (count[c] < cou)
                    rm += count[c];
                else
                    rm += max(0, count[c] - (cou + k));
                if (rm > best)
                    break;
            }
            best = min(best, rm);
        }
        return best;
    }
};