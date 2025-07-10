class Solution {
public:
    int maxFreeTime(int eventTime, const vector<int>& startTime,
                    const vector<int>& endTime) {
        const int n = startTime.size();
#if 1
        int max_pause = 0;
        int max_pause_i = -1;
        for (int i = 0; i < n + 1; ++i) {
            const int last_end = i == 0 ? 0 : endTime[i - 1];
            const int cur_start = i == n ? eventTime : startTime[i];
            const int pause = cur_start - last_end;
            if (pause > max_pause) {
                max_pause = pause;
                max_pause_i = i;
            }
        }

        int best = 0;
        for (int i = 0; i < n; ++i) {
            const int last_end = i == 0 ? 0 : endTime[i - 1];
            const int next_start = i == n - 1 ? eventTime : startTime[i + 1];

            const int prev_pause = startTime[i] - last_end;
            const int next_pause = next_start - endTime[i];
            const int cur_time = endTime[i] - startTime[i];

            bool can_move;
            if (max_pause_i == i || max_pause_i == i + 1) {
                can_move = false;
                // search for alternative move-slot
                for (int j = 0; j < n + 1; ++j) {
                    if (j == i || j == i + 1)
                        continue;
                    const int last_end = j == 0 ? 0 : endTime[j - 1];
                    const int cur_start = j == n ? eventTime : startTime[j];
                    const int pause = cur_start - last_end;
                    if (pause >= cur_time) {
                        can_move = true;
                        break;
                    }
                }
            } else {
                can_move = max_pause >= cur_time;
            }

            const int pause =
                prev_pause + next_pause + (can_move ? cur_time : 0);
            best = max(best, pause);
        }
        return best;
#else
        multiset<int> pauses{};
        for (int i = 0; i < n + 1; ++i) {
            const int last_end = i == 0 ? 0 : endTime[i - 1];
            const int cur_start = i == n ? eventTime : startTime[i];
            pauses.insert(cur_start - last_end);
        }

        int best = 0;
        for (int i = 0; i < n; ++i) {
            const int last_end = i == 0 ? 0 : endTime[i - 1];
            const int next_start = i == n - 1 ? eventTime : startTime[i + 1];

            const int prev_pause = startTime[i] - last_end;
            const int next_pause = next_start - endTime[i];
            const int cur_time = endTime[i] - startTime[i];
            pauses.erase(pauses.find(prev_pause));
            pauses.erase(pauses.find(next_pause));

            const bool can_move = pauses.lower_bound(cur_time) != pauses.end();
            const int pause =
                prev_pause + next_pause + (can_move ? cur_time : 0);
            best = max(best, pause);

            pauses.insert(prev_pause);
            pauses.insert(next_pause);
        }
        return best;
#endif
    }
};