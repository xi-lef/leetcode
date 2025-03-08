class Solution {
public:
    int climbStairs(int n) {
        if (memo[n])
            return memo[n];

        return memo[n] = (n <= 3) ? n : climbStairs(n - 1) + climbStairs(n - 2);
    }

private:
    static inline int memo[46];
};