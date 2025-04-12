class Solution {
public:
    int maxArea(const vector<int>& height) {
        int a = 0;
        int b = height.size() - 1;
        int max_area = 0;
        int ha = height[a];
        int hb = height[b];
        while (a < b) {
            max_area = max(max_area, min(ha, hb) * (b - a));
            if (ha < hb)
                ha = height[++a];
            else
                hb = height[--b];
        }
        return max_area;
    }
};