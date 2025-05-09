class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen{};
        while (n != 1 && !seen.contains(n)) {
            seen.insert(n);
            int next = 0;
            while (n) {
                const int d = n % 10;
                next += d * d;
                n /= 10;
            }
            n = next;
        }
        return n == 1;
    }
};