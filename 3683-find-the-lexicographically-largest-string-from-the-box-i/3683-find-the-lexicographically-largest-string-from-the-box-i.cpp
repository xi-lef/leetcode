class Solution {
public:
    string answerString(const string& word, int numFriends) {
        if (numFriends == 1)
            return word;

        const int n = word.size();
        const char largest = *ranges::max_element(word);
        vector<int> indices{};
        for (int i = 0; i < n; ++i) {
            if (word[i] == largest)
                indices.push_back(i);
        }

        const string_view sv{word};
        string_view answer{};
        for (const int& i : indices) {
            answer = max(answer, sv.substr(i, n - (numFriends - 1)));
        }
        return string{answer};
    }
};