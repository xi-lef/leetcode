class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        const int n = digits.size();
        ranges::sort(digits);

        vector<int> answer{};
        for (int i = 0; i < n;) {
            const int d = digits[i];
            if (d == 0) {
                ++i;
                continue;
            }
            for (int j = 0; j < n;) {
                if (j == i) {
                    ++j;
                    continue;
                }
                const int e = digits[j];
                for (int k = 0; k < n;) {
                    const int f = digits[k];
                    if (k == j || k == i || f % 2) {
                        ++k;
                        continue;
                    }
                    answer.push_back(d * 100 + e * 10 + f);
                    while (++k < n && digits[k] == f)
                        ;
                }
                while (++j < n && digits[j] == e)
                    ;
            }
            while (++i < n && digits[i] == d)
                ;
        }
        return answer;
    }
};