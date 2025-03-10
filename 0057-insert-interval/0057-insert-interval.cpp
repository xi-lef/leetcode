class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> intervals,
                               vector<int>& newInterval) {
        if (intervals.empty()) {
            return {newInterval};
        }

        const int& start_new = newInterval[0];
        const int& end_new = newInterval[1];
        for (auto i = intervals.begin(); i != intervals.end(); ++i) {
            int& start_i = (*i)[0];
            int& end_i = (*i)[1];
            if ((start_i <= start_new && start_new <= end_i) ||
                start_new <= start_i && start_i <= end_new) {
                if (start_new < start_i) {
                    start_i = start_new;
                }
                if (end_new > end_i) {
                    end_i = end_new;
                    auto j = i + 1;
                    while (j != intervals.end() && (*j)[0] <= end_new) {
                        end_i = max((*j)[1], end_new);
                        ++j;
                    }
                    intervals.erase(i + 1, j);
                }

                return intervals;
            } else if (end_new < start_i &&
                       (i == intervals.begin() || start_new > (*(i - 1))[1])) {
                intervals.insert(i, newInterval);
                return intervals;
            }
        }

        intervals.push_back(newInterval);
        return intervals;
    }
};