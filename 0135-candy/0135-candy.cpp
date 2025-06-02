class Solution {
public:
    int candy(const vector<int>& ratings) {
        const int n = ratings.size();
        if (n == 1)
            return 1;

#if 1
        int answer = 1;
        int candies = 1;
        int count = 0;
        for (int i = 1; i < n; ++i) {
            const int cur = ratings[i];
            const int prev = ratings[i - 1];
            if (cur > prev) {
                ++candies;
                answer += candies;
            } else if (cur < prev) {
                --candies;
                answer += candies;
                ++count;
                if (i == n - 1 || ratings[i + 1] >= cur) {
                    // Also adjust/offset the first child that wasn't counted if
                    // candies is negative. If >=0, the amount from previously
                    // incrementing is correct.
                    count += candies <= 0;
                    answer += count * (1 - candies);

                    count = 0;
                    candies = 1;
                }
            } else {
                answer += count * (1 - candies);

                count = 0;
                candies = 1;
                answer += candies;
            }
        }
        return answer;
#else
        vector<int> minima{};
        unordered_set<int> maxima{};
        if (ratings[0] <= ratings[1])
            minima.push_back(0);
        else
            maxima.insert(0);
        if (ratings[n - 1] <= ratings[n - 2])
            minima.push_back(n - 1);
        else
            maxima.insert(n - 1);

        for (int i = 1; i < n - 1; ++i) {
            const int prev = ratings[i - 1];
            const int cur = ratings[i];
            const int next = ratings[i + 1];
            if ((cur <= prev && cur < next) || (cur < prev && cur <= next))
                minima.push_back(i);
            if ((cur >= prev && cur > next) || (cur > prev && cur >= next))
                maxima.insert(i);
        }

        vector<int> candies(n, 1);
        for (const int& mi : minima) {
            candies[mi] = 1;
            int c = 1;
            for (int i = mi - 1; i >= 0; --i) {
                if (ratings[i] > ratings[i + 1])
                    ++c;
                candies[i] = max(candies[i], c);
                if (maxima.contains(i))
                    break;
            }
            c = 1;
            for (int i = mi + 1; i < n; ++i) {
                if (ratings[i] > ratings[i - 1])
                    ++c;
                candies[i] = max(candies[i], c);
                if (maxima.contains(i))
                    break;
            }
        }
        return ranges::fold_left(candies, 0, plus{});
#endif
    }
};