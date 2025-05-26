class Solution {
public:
    int finalValueAfterOperations(const vector<string>& operations) {
        int X = 0;
        for (const string& s : operations)
            X += s[1] == '+' ? 1 : -1;
        return X;
    }
};