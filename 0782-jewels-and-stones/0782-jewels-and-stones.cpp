class Solution {
public:
    int numJewelsInStones(const string& jewels, const string& stones) {
        const unordered_set<char> js{jewels.begin(), jewels.end()};
        int answer = 0;
        for (const char& c : stones)
            answer += js.contains(c);
        return answer;
    }
};