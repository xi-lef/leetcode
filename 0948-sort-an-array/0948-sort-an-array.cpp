class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //quicksort(nums);
        //mergesort(nums);
        //mergesort2(nums);
        //insertionsort(nums);
        //heapsort(nums);
        //radixsort_lsd_dec(nums);
        //radixsort_msd_bin(nums);
        //radixsort_lsd_bits<8>(nums);
        //countingsort(nums);
        introsort(nums);
        return nums;
    }

private:
    void radixsort_lsd_dec(vector<int>& nums) {
        const int max = abs(*ranges::max_element(
            nums, {}, [](const int& i) { return abs(i); }));
        array<vector<int>, 10> buckets{};
        for (int factor = 1; factor <= max; factor *= 10) {
            for (const int& num : nums)
                buckets[abs(num / factor % 10)].push_back(num);

            for (auto it = nums.begin(); auto& bucket : buckets) {
                it = ranges::copy(bucket, it).out;
                bucket.clear();
            }
        }

        // sort negatives
        for (const int& num : nums) {
            buckets[num < 0].push_back(num);
        }
        const auto it = ranges::reverse_copy(buckets[1], nums.begin()).out;
        ranges::copy(buckets[0], it);
    }

    static constexpr int sign_pos = numeric_limits<int>::digits;
    void flip_sign(vector<int>& nums) {
        for (int& num : nums)
            num ^= 1 << sign_pos;
    }

    void radixsort_msd_bin(vector<int>& nums, int l, int r, int bit) {
        if (l >= r || bit == -1)
            return;

        int bin0 = l;
        int bin1 = r;
        while (bin0 <= bin1) {
            int& num = nums[bin0];
            // if ((bit == sign_pos && ((num >> bit) & 1) == 0) || (bit !=
            // sign_pos && ((num
            // >> bit) & 1) == 1))
            // if (((num ^ 0x80000000) >> bit) & 1)
            // if ((num >> bit) & 1) // with flip_sign()
            if (((num >> bit) & 1) == (bit != sign_pos))
                swap(num, nums[bin1--]);
            else
                ++bin0;
        }

        radixsort_msd_bin(nums, l, bin1, bit - 1);
        radixsort_msd_bin(nums, bin0, r, bit - 1);
    }
    void radixsort_msd_bin(vector<int>& nums) {
        radixsort_msd_bin(nums, 0, nums.size() - 1, sign_pos);
    }

    template <int bits> void radixsort_lsd_bits(vector<int>& nums) {
        flip_sign(nums);

        constexpr int num_buckets = 1 << bits;
        constexpr int mask = num_buckets - 1;
        array<vector<int>, num_buckets> buckets{};
        for (int shift = 0; shift < 32; shift += bits) {
            for (const int& num : nums)
                buckets[(num >> shift) & mask].push_back(num);

            for (auto it = nums.begin(); auto& bucket : buckets) {
                it = ranges::copy(bucket, it).out;
                bucket.clear();
            }
        }

        flip_sign(nums);
    }

    void countingsort(vector<int>& nums) {
#if 0
        constexpr int min = -50000;
        array<int, 100001> counts{};
#else
        const int min = *ranges::min_element(nums);
        const int max = *ranges::max_element(nums);
        vector<int> counts(max - min + 1);
#endif

        for (const int& num : nums)
            ++counts[num - min];

        int i = 0;
        for (int j = 0; j < counts.size(); ++j) {
            for (int count = counts[j]; count; --count)
                nums[i++] = j + min;
        }
    }

    void build_max_heap(vector<int>& nums, int l, int r) {
        for (int i = l + (r - l) / 2; i >= l; --i)
            max_heapify(nums, l, r, i);
    }

    void max_heapify(vector<int>& nums, int l, int r, int i) {
#if 1
        for (;;) {
            const int child1 = 2 * (i - l) + 1 + l;
            const int child2 = child1 + 1;
            int m = i;
            if (child1 <= r && nums[child1] > nums[m])
                m = child1;
            if (child2 <= r && nums[child2] > nums[m])
                m = child2;
            if (m == i)
                break;
            swap(nums[i], nums[m]);
            i = m;
        }
#else
        const int child1 = 2 * (i - l) + 1 + l;
        const int child2 = child1 + 1;
        int m = i;
        if (child1 <= r && nums[child1] > nums[m])
            m = child1;
        if (child2 <= r && nums[child2] > nums[m])
            m = child2;
        if (m != i) {
            swap(nums[i], nums[m]);
            max_heapify(nums, l, r, m);
        }
#endif
    }

    void heapsort(vector<int>& nums, int l, int r) {
        build_max_heap(nums, l, r);
        for (int i = r; i > l; --i) {
            swap(nums[l], nums[i]);
            max_heapify(nums, l, i - 1, l);
        }
    }
    void heapsort(vector<int>& nums) { heapsort(nums, 0, nums.size() - 1); }

    void mergesort2(vector<int>& output, vector<int>& input, int l, int r) {
        if (l == r)
            return;

        const int m = l + (r - l) / 2;
        mergesort2(input, output, l, m);
        mergesort2(input, output, m + 1, r);
        merge2(output, l, m, r, input);
    }
    void mergesort2(vector<int>& nums) {
        vector<int> tmp{nums};
        mergesort2(nums, tmp, 0, nums.size() - 1);
    }

    void merge2(vector<int>& output, int l, int m, int r, vector<int>& input) {
        int a = l;
        int b = m + 1;
        for (int i = l; i <= r; ++i) {
            if (b > r || a <= m && input[a] < input[b])
                output[i] = input[a++];
            else
                output[i] = input[b++];
        }
    }

    void mergesort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;

        const int m = l + (r - l) / 2;
        mergesort(nums, l, m);
        mergesort(nums, m + 1, r);
        merge(nums, l, m, r);
    }
    void mergesort(vector<int>& nums) { mergesort(nums, 0, nums.size() - 1); }

    void merge(vector<int>& nums, int l, int m, int r) {
        vector<int> tmp(r - l + 1);
        int a = l;
        int b = m + 1;
        for (int i = 0; i < tmp.size(); ++i) {
            if (b > r || a <= m && nums[a] < nums[b])
                tmp[i] = nums[a++];
            else
                tmp[i] = nums[b++];
        }
        ranges::copy(tmp, nums.begin() + l);
    }

    void insertionsort(vector<int>& nums, int l, int r) {
        for (int i = l + 1; i <= r; ++i) {
            const int insert = nums[i];
            int j;
            for (j = i; j > l && nums[j - 1] > insert; --j)
                nums[j] = nums[j - 1];
            nums[j] = insert;
        }
    }
    void insertionsort(vector<int>& nums) {
        insertionsort(nums, 0, nums.size() - 1);
    }

    void quicksort(vector<int>& nums, int l, int r) {
        if (l >= r)
            return;

        const int mid = partition(nums, l, r);
        // quicksort(nums, l, mid - 1); // Lomuto
        quicksort(nums, l, mid); // Hoare
        quicksort(nums, mid + 1, r);
    }
    void quicksort(vector<int>& nums) { quicksort(nums, 0, nums.size() - 1); }

    int partition(vector<int>& nums, int l, int r) {
#if 0
        // Lomuto
        const int pivot = nums[r];
        int mid = l;
        while (l < r) {
            if (nums[l] < pivot) {
                swap(nums[mid], nums[l]);
                ++mid;
            }
            ++l;
        }
        swap(nums[mid], nums[r]);
        return mid;
#else
        // Hoare
        // const int pivot = nums[l];
        const int pivot = nums[l + (r - l) / 2];
        int i = l - 1;
        int j = r + 1;
        for (;;) {
            do
                ++i;
            while (nums[i] < pivot);
            do
                --j;
            while (nums[j] > pivot);
            if (i >= j)
                return j;
            swap(nums[i], nums[j]);
        }
#endif
    }

    void introsort(vector<int>& nums, int l, int r, int depth) {
        if (l >= r)
            return;

        if (r - l <= 16) {
            insertionsort(nums, l, r);
        } else if (depth == 0) {
            heapsort(nums, l, r);
        } else {
            const int mid = partition(nums, l, r);
            // introsort(nums, l, mid - 1, depth - 1); // Lomuto
            introsort(nums, l, mid, depth - 1); // Hoare
            introsort(nums, mid + 1, r, depth - 1);
        }
    }
    void introsort(vector<int>& nums) {
        const int n = nums.size();
        introsort(nums, 0, n - 1, floor(log2(n)) * 2);
    }
};