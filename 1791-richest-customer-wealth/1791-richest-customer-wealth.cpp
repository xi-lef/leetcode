class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int answer = 0;
        for (const auto& customer : accounts) {
            answer = max(answer, *ranges::fold_left_first(customer, plus{}));
        }
        return answer;
    }
};