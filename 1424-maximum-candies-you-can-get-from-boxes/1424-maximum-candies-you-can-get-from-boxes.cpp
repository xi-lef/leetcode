class Solution {
public:
    int maxCandies(vector<int>& status, const vector<int>& candies,
                   vector<vector<int>>& containedKeys,
                   vector<vector<int>>& containedBoxes,
                   vector<int>& boxes) {
#if 0
        int answer = 0;
        unordered_set<int> keys{};
        for (;;) {
            bool change = false;
            vector<int> new_boxes{};
            for (const int& box : boxes) {
                if (!status[box] && !keys.contains(box)) {
                    new_boxes.push_back(box);
                    continue;
                }

                change = true;
                answer += candies[box];
                ranges::move(containedBoxes[box], back_inserter(new_boxes));
                ranges::move(containedKeys[box], inserter(keys, keys.end()));
            }

            if (!change)
                break;
            boxes = move(new_boxes);
        }
        return answer;
#else
        int answer = 0;
        stack<int> unlocked_boxes{};
        unordered_set<int> locked_boxes{};
        for (const int& box : boxes) {
            if (status[box])
                unlocked_boxes.push(box);
            else
                locked_boxes.insert(box);
        }

        while (!unlocked_boxes.empty()) {
            const int box = unlocked_boxes.top();
            unlocked_boxes.pop();

            answer += candies[box];
            for (const int& b : containedBoxes[box]) {
                if (status[b])
                    unlocked_boxes.push(b);
                else
                    locked_boxes.insert(b);
            }
            for (const int& k : containedKeys[box]) {
                status[k] = 1;
                if (locked_boxes.contains(k)) {
                    locked_boxes.erase(k);
                    unlocked_boxes.push(k);
                }
            }
        }
        return answer;
#endif
    }
};