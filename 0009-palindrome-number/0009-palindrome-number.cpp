class Solution {
public:
    int head;
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        head = x;
        return check(x);
    }

    bool check(int x) {
        if (x == 0)
            return true;
        const bool ans = check(x / 10) && x % 10 == head % 10;
        head /= 10;
        return ans;
    }
};