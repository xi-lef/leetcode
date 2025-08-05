class Solution {
public:
    int numOfUnplacedFruits(const vector<int>& fruits, vector<int>& baskets) {
        int answer = 0;
        for (const int& fruit : fruits) {
            if ([&]() {
                    for (int& basket : baskets) {
                        if (basket >= fruit) {
                            basket = 0;
                            return false;
                        }
                    }
                    return true;
                }())
                ++answer;
        }
        return answer;
    }
};