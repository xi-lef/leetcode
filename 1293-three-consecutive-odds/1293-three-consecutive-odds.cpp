class Solution {
public:
    bool threeConsecutiveOdds(const vector<int>& arr) {
        int odds = 0;
        for (const int& i : arr) {
            if (i % 2) {
                if (++odds == 3)
                    return true;
            } else {
                odds = 0;
            }
        }
        return false;
    }
};