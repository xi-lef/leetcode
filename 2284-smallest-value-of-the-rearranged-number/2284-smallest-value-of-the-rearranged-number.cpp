class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0)
            return 0;

        const bool negative = num < 0;
        if (num < 0)
            num = -num;
        vector<int> digits{};
        while (num) {
            digits.push_back(num % 10);
            num /= 10;
        }

        if (negative)
            ranges::sort(digits, greater{});
        else
            ranges::sort(digits);
        long long answer = 0;
        int first =
            *ranges::find_if(digits, [](const int& i) { return i != 0; });
        answer += first;
        for (const int& d : digits) {
            if (d == first) {
                first = -1;
                continue;
            }
            answer *= 10;
            answer += d;
        }
        return negative ? -answer : answer;
    }
};