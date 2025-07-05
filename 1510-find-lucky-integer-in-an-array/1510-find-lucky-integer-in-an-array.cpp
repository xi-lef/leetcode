class Solution {
public:
    int findLucky(const vector<int>& arr) {
        array<int, 501> count{};
        for (const int& i : arr)
            ++count[i];

        for (int i = count.size() - 1; i > 0; --i) {
            if (count[i] == i)
                return i;
        }
        return -1;
    }
};