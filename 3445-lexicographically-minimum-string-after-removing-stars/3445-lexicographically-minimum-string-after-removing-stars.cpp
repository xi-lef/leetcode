class Solution {
public:
    string clearStars(string& s) {
#if 1
        array<stack<int, vector<int>>, 26> stacks{};
        char lowest = 'z';
        for (int i = 0; i < s.size(); ++i) {
            char& c = s[i];
            if (c == '*') {
#if 0
                for (auto& st : stacks) {
                    if (st.empty())
                        continue;

                    s[st.top()] = '*';
                    st.pop();
                    break;
                }
#else
                auto& st = stacks[lowest - 'a'];
                s[st.top()] = '*';
                st.pop();
                if (st.empty()) {
                    do
                        ++lowest;
                    while (lowest < 'z' && stacks[lowest - 'a'].empty());
                }
#endif
            } else {
                stacks[c - 'a'].push(i);
                lowest = min(lowest, c);
            }
        }
#else
        priority_queue<pair<char, int>, vector<pair<char, int>>,
                       decltype([](const auto& a, const auto& b) {
                           if (a.first != b.first)
                               return a.first > b.first;
                           return a.second < b.second;
                       })>
            pq{};
        for (int i = 0; i < s.size(); ++i) {
            char& c = s[i];
            if (c == '*') {
                s[pq.top().second] = '*';
                pq.pop();
            } else {
                pq.emplace(c, i);
            }
        }
#endif
        erase(s, '*');
        return s;
    }
};