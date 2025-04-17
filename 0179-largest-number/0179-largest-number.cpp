class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if (ranges::all_of(nums, [](const int& i) { return i == 0; }))
            return "0";

        vector<string> strings{};
        ranges::transform(nums, back_inserter(strings),
                          static_cast<std::string (*)(int)>(to_string));
        ranges::sort(strings, [](const string& a, const string& b) {
            return a + b > b + a;
        });

        string answer{};
        for (string& s : strings) {
            answer += move(s);
        }
        return answer;
    }
};