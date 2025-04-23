class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        ranges::sort(ranges);
        for (const vector<int>& range : ranges) {
            if (range.front() <= left && left <= range.back()) {
                left = range.back() + 1;
            }
        }
        return left > right;
    }
};