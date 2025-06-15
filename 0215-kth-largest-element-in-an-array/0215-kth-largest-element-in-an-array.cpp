class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickselect(nums, k);
    }

private:
    int quickselect(vector<int>& nums, int k) {
        int l = 0;
        int h = nums.size() - 1;
        k = nums.size() - k; // k-th smallest
        while (l < h) {
            const int pivot = nums[h];
            int i = l - 1;
            int j = h + 1;
            for (;;) {
                do
                    ++i;
                while (nums[i] < pivot);
                do
                    --j;
                while (nums[j] > pivot);
                if (i >= j)
                    break;
                swap(nums[i], nums[j]);
            }
            const int mid = j;

            if (mid == k)
                return pivot;
            else if (mid < k)
                l = mid + 1;
            else
                h = mid - (mid == h);
        }
        return nums[l];
    }
};