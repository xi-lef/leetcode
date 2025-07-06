class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2)
        : nums1(nums1), nums2(nums2) {
        ranges::sort(this->nums1);
        for (const int& num : this->nums2)
            ++map2[num];
    }

    void add(int index, int val) {
        map2[nums2[index]] -= 1;
        map2[nums2[index] += val] += 1;
    }

    int count(int tot) {
        int c = 0;
        for (const int& num : nums1) {
            if (num >= tot)
                break;
            if (map2.contains(tot - num))
                c += map2[tot - num];
        }
        return c;
    }

private:
    vector<int>& nums1;
    vector<int>& nums2;
    unordered_map<int, int> map2{};
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */