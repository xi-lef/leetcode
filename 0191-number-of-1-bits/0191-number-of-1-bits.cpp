class Solution {
public:
    int hammingWeight(int n) { return popcount(static_cast<unsigned int>(n)); }
};