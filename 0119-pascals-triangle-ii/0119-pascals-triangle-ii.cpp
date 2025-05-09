class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> answer(rowIndex + 1, 1);
        for (int i = 1; i < rowIndex; ++i) {
            int save = answer[0];
            for (int j = 1; j <= i; ++j)
                save = exchange(answer[j], save + answer[j]);
        }
        return answer;
    }
};