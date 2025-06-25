class Solution {
public:
    long long kMirror(int k, int n) {
        long long answer = 0;
        long long start = 1;
        for (;;) {
            const long long limit = 10 * start;

            // palindrome with 2*d - 1 digits
            for (long long num = start; num < limit; ++num) {
                long long reverse = 0;
                for (long long i = num; i; i /= 10)
                    reverse = reverse * 10 + i % 10;

                const long long pali = num / 10 * limit + reverse;
                if (is_mirror(k, pali)) {
                    answer += pali;
                    if (--n == 0)
                        return answer;
                }
            }

            // palindrome with 2*d digits
            for (long long num = start; num < limit; ++num) {
                long long reverse = 0;
                for (long long i = num; i; i /= 10)
                    reverse = reverse * 10 + i % 10;

                const long long pali = num * limit + reverse;
                if (is_mirror(k, pali)) {
                    answer += pali;
                    if (--n == 0)
                        return answer;
                }
            }

            start *= 10;
        }
    }

private:
    bool is_mirror(int k, long long num) {
        long long limit = 1;
        while (limit * k <= num)
            limit *= k;

        while (num) {
            if (num / limit != num % k)
                return false;
            num %= limit;
            num /= k;
            limit /= k * k;
        }
        return true;
    }
};