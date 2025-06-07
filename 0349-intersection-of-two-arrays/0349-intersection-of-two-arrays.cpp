class Solution {
public:
    vector<int> intersection(const vector<int>& nums1,
                             const vector<int>& nums2) {
#if 0
        set<int> set1{nums1.begin(), nums1.end()};
        set<int> set2{nums2.begin(), nums2.end()};
        vector<int> answer{};
        ranges::set_intersection(set1, set2, back_inserter(answer));
        return answer;
#else
        unordered_set<int> set1{nums1.begin(), nums1.end()};
        vector<int> answer{};
        for (const int& i : nums2) {
            if (set1.contains(i)) {
                set1.erase(i);
                answer.push_back(i);
            }
        }
        return answer;
#endif
    }
};