class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ranges::sort(intervals, {}, [](auto& v) { return v.front(); });

#if 1
        int cur = 0;
        int next = 1;
        while (next < intervals.size()) {
            auto& i = intervals[cur];
            const int i_start = i.front();
            int& i_end = i.back();

            auto& j = intervals[next];
            int& j_start = j.front();
            if (j_start <= i_end) {
                i_end = max(i_end, j.back());
                j_start = -1;
            } else {
                cur = next;
            }
            ++next;
        }
        erase_if(intervals, [](auto& v) { return v.front() == -1; });
        return intervals;
#else
        vector<vector<int>> answer{};
        for (int i = 0; i < intervals.size(); ++i) {
            const auto& cur = intervals[i];
            if (i == intervals.size() - 1) {
                answer.push_back(move(cur));
                break;
            }
            const int& i_start = cur.front();
            int i_end = cur.back();

            while (i + 1 < intervals.size()) {
                const auto& next = intervals.begin() + i + 1;
                const int& next_start = next->front();
                if (next_start <= i_end) {
                    i_end = max(i_end, next->back());
                    ++i;
                } else {
                    break;
                }
            }
            answer.emplace_back(initializer_list{i_start, i_end});
        }
        return answer;
#endif
    }
};