class Solution {
public:
    double myPow(double x, int n) {
        double answer = 1;
        double tmp = x;
        while (n) {
            if (n % 2) {
                if (n < 0)
                    answer /= tmp;
                else
                    answer *= tmp;
            }
            n /= 2;
            tmp *= tmp;
        }
        return answer;
    }
};