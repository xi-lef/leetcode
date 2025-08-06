class MaxSegmentTree {
public:
    MaxSegmentTree(const vector<int>& values) : data(2 * values.size()) {
        construct(values, 0, values.size() - 1, 0);
    }

    int find(int l, int r, int i, int value) {
        if (l == r) {
            return data[i] >= value ? l : -1;
        }

        const int m = l + (r - l) / 2;
        // indices calculated as shown on
        // https://cp-algorithms.com/data_structures/segment_tree.html#memory-efficient-implementation
        const int li = i + 1;
        const int ri = i + 2 * (m - l + 1);
        if (data[li] >= value)
            return find(l, m, li, value);
        else if (data[ri] >= value)
            return find(m + 1, r, ri, value);
        else
            return -1;
    }

    void update(int l, int r, int i, int pos, int val) {
        if (l == r) {
            data[i] = val;
            return;
        }

        const int m = l + (r - l) / 2;
        const int li = i + 1;
        const int ri = i + 2 * (m - l + 1);
        if (pos <= m)
            update(l, m, li, pos, val);
        else
            update(m + 1, r, ri, pos, val);
        data[i] = max(data[li], data[ri]);
    }

private:
    vector<int> data;

    void construct(const vector<int>& values, int l, int r, int i) {
        if (l == r) {
            data[i] = values[l];
            return;
        }

        const int m = l + (r - l) / 2;
        const int li = i + 1;
        const int ri = i + 2 * (m - l + 1);
        construct(values, l, m, li);
        construct(values, m + 1, r, ri);
        data[i] = max(data[li], data[ri]);
    }
};

class Solution {
public:
    int numOfUnplacedFruits(const vector<int>& fruits,
                            const vector<int>& baskets) {
        const int n = baskets.size();
        MaxSegmentTree mst{baskets};

        int answer = 0;
        for (const int& fruit : fruits) {
            const int i = mst.find(0, n - 1, 0, fruit);
            if (i != -1) {
                mst.update(0, n - 1, 0, i, 0);
            } else {
                ++answer;
            }
        }
        return answer;
    }
};