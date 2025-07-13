class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        ranges::sort(players);
        ranges::sort(trainers);
        const int tn = trainers.size();

        int answer = 0;
        for (int p = 0, t = 0; p < players.size(); ++p, ++t) {
            while (t < tn && players[p] > trainers[t])
                ++t;
            if (t >= tn)
                break;
            ++answer;
        }
        return answer;
    }
};