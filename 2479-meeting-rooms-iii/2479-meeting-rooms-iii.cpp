class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        ranges::sort(meetings, {}, [](const auto& m) { return m.front(); });

        priority_queue<int, vector<int>, greater<>> free_rooms{};
        for (int i = 0; i < n; ++i)
            free_rooms.push(i);
        vector<int> count(n);
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<>>
            ongoing{};
        long time = 0;
        for (const auto& meeting : meetings) {
            const int start_i = meeting.front();
            const int end_i = meeting.back();
            time = max(time, static_cast<long>(start_i));
            // check currently held meetings that finished
            while (!ongoing.empty() && ongoing.top().first <= time) {
                free_rooms.push(ongoing.top().second);
                ongoing.pop();
            }

            int room;
            if (!free_rooms.empty()) {
                room = free_rooms.top();
                free_rooms.pop();
            } else {
                // wait for next meeting to finish
                time = ongoing.top().first;
                room = ongoing.top().second;
                ongoing.pop();
            }

            ongoing.emplace(time + (end_i - start_i), room);
            ++count[room];
        }

        int best = 0;
        int answer = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > best) {
                best = count[i];
                answer = i;
            }
        }
        return answer;
    }
};