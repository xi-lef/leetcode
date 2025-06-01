class Solution {
public:
    int leastInterval(const vector<char>& tasks, int n) {
        vector<int> counts(26);
        for (const char& c : tasks)
            ++counts[c - 'A'];
        ranges::sort(counts, ranges::greater{});
        erase(counts, 0);

        int answer = 0;
        while (!counts.empty()) {
            int i;
            for (i = 0; i < n + 1 && i < counts.size(); ++i) {
                ++answer;
                --counts[i];
            }

            ranges::sort(counts, ranges::greater{});
            erase(counts, 0);
            if (!counts.empty())
                answer += n + 1 - i;
        }
        return answer;
    }
};