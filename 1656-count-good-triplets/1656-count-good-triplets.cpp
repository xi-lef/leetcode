class Solution {
public:
    int countGoodTriplets(const vector<int>& arr, int a, int b, int c) {
        const int n = arr.size();
        int ans = 0;
        for (int k = 2; k < n; ++k) {
            for (int j = 1; j < k; ++j) {
                for (int i = 0; i < j; ++i) {
                    if (abs(arr[i] - arr[j]) <= a &&
                        abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c)
                        ++ans;
                }
            }
        }
        return ans;
    }
};