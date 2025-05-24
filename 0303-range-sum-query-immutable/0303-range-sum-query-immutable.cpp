class NumArray {
public:
    NumArray(const vector<int>& nums) : prefix_sums(nums.size()) {
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            prefix_sums[i] = sum;
        }
    }

    int sumRange(int left, int right) {
        return prefix_sums[right] - (left > 0 ? prefix_sums[left - 1] : 0);
    }

private:
    vector<int> prefix_sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */