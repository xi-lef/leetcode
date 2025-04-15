class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> answer(temperatures.size());
        for (int i = temperatures.size() - 2; i >= 0; --i) {
            int next = i + 1;
            while (temperatures[next] <= temperatures[i]) {
                if (answer[next] == 0) {
                    next = i;
                    break;
                }
                next += answer[next];
            }
            answer[i] = next - i;
        }
        return answer;
    }
};