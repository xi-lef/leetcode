class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        ranges::sort(events, {}, [](const auto& v) { return v.front(); });
        const int n = events.size();

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype([](const auto& a, const auto& b) {
                           return a.second > b.second;
                       })>
            pq{};
        int i = 0;
        int day = 1;
        int answer = 0;
        while (i < n || !pq.empty()) {
            while (i < n && (events[i].front() <= day || pq.empty())) {
                day = max(day, events[i].front());
                pq.emplace(events[i].front(), events[i].back());
                ++i;
            }

            while (!pq.empty() && pq.top().second < day)
                pq.pop();
            if (!pq.empty()) {
                ++answer;
                ++day;
                pq.pop();
            }
        }
        return answer;
    }
};