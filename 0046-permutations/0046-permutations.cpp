class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
#if 0
        ranges::sort(nums);
        vector<vector<int>> answer{};
        do {
            answer.push_back(nums);
        } while (ranges::next_permutation(nums).found);
        return answer;
#else
        set<vector<int>> answer{nums};
        bla(answer, nums);
        return {answer.begin(), answer.end()};
#endif
    }

    void bla(set<vector<int>>& answer, vector<int>& cur, int n = 0) {
        for (int i = n + 1; i < cur.size(); ++i) {
            bla(answer, cur, n + 1);
            swap(cur[n], cur[i]);
            answer.insert(cur);
            bla(answer, cur, n + 1);
            swap(cur[n], cur[i]);
        }
    }
};