class Solution {
public:
    vector<int> intersect(const vector<int>& nums1, const vector<int>& nums2) {
        unordered_multiset<int> set1{nums1.begin(), nums1.end()};
        vector<int> answer{};
        for (const int& i : nums2) {
            if (set1.contains(i)) {
                set1.extract(i);
                answer.push_back(i);
            }
        }
        return answer;
    }
};