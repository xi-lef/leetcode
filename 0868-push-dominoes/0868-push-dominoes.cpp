class Solution {
public:
    string pushDominoes(const string& dominoes) {
        string answer{dominoes};
        int last_pos = -1;
        char last_dom = '.';
        for (int i = 0; i < dominoes.size(); ++i) {
            const char dom = dominoes[i];
            if (dom == '.')
                continue;

            if (dom == last_dom) {
                for (int j = last_pos + 1; j < i; ++j)
                    answer[j] = dom;
            } else if (dom == 'L') {
                if (last_pos == -1) {
                    for (int j = 0; j < i; ++j)
                        answer[j] = 'L';
                } else {
                    const int diff = i - last_pos;
                    for (int j = 1; j < (diff + 1) / 2; ++j) {
                        answer[last_pos + j] = 'R';
                        answer[i - j] = 'L';
                    }
                }
            }

            last_pos = i;
            last_dom = dom;
        }
        if (last_dom == 'R') {
            for (int j = last_pos + 1; j < answer.size(); ++j)
                answer[j] = 'R';
        }
        return answer;
    }
};