class Solution {
public:
    string maximumBinaryString(string& binary) {
#if 1
        const int zeros = ranges::count(binary, '0');
        const auto first_zero = ranges::find(binary, '0');
        if (first_zero == binary.end())
            return binary;

        string answer(binary.size(), '1');
        answer[first_zero - binary.begin() + zeros - 1] = '0';
        return answer;
#else
        vector<int> zeros{};
        for (int i = 0; i + 1 < binary.size(); ++i) {
            char& cur = binary[i];
            char& next = binary[i + 1];

            if (cur == '0') {
                if (next == '0')
                    cur = '1';
                else
                    zeros.push_back(i);
            } else if (cur == '1' && next == '0' && !zeros.empty()) {
                next = '1';
                int j;
                while (!zeros.empty()) {
                    const int z = zeros.back();
                    zeros.pop_back();
                    binary[z] = '1';
                    j = z + 1;
                }
                binary[j] = '0';
                zeros.push_back(j);
            }
        }
        return binary;
#endif
    }
};