#include <ranges>

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        ranges::sort(points, {}, [](const vector<int>& point) {
            return point.front() * point.front() + point.back() * point.back();
        });
        points.erase(points.begin() + k, points.end());
        return points;
    }
};