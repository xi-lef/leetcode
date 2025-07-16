class Solution {
public:
    int maximum69Number(int num) {
        int magnitude = 1;
        int best = 0;
        while (num > magnitude) {
            if (num / magnitude % 10 == 6)
                best = magnitude;
            magnitude *= 10;
        }
        return num + best * 3;
    }
};