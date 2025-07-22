class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        const int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int j = i;
            while (nums[j] != j + 1) {
                int& a = nums[j];
                int& b = nums[a - 1];
                if (a == b)
                    break;
                swap(a, b);
            }
        }

        int new_size = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1)
                nums[new_size++] = i + 1;
        }
        nums.resize(new_size);
        return nums;
    }
};