class Solution {
public:
    string triangleType(vector<int>& nums) {
        ranges::sort(nums);
        const int a = nums[0];
        const int b = nums[1];
        const int c = nums[2];

        if (a + b <= c)
            return "none";
        if (a == b && b == c)
            return "equilateral";
        if (a == b || a == c || b == c)
            return "isosceles";
        return "scalene";
    }
};