class Solution {
public:
    int findClosest(int x, int y, int z) {
        const int p1 = abs(z - x);
        const int p2 = abs(z - y);
        if (p1 < p2)
            return 1;
        else if (p2 < p1)
            return 2;
        else
            return 0;
    }
};