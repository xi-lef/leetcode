class Solution {
public:
    string addBinary(string a, string b) {
        const size_t as = a.size();
        const size_t bs = b.size();
        if (as != bs) {
            string& s = as < bs ? a : b;
            s.insert(0, as > bs ? as - bs : bs - as, '0');
        }
        assert(a.size() == b.size());

        const size_t n = a.size();
        string result(n, '0');
        bool carry = 0;
        for (int i = n - 1; i >= 0; --i) {
            const bool ai = a[i] == '1';
            const bool bi = b[i] == '1';
            result[i] = (ai ^ bi ^ carry) ? '1' : '0';
            carry = (ai + bi + carry) > 1;
        }
        if (carry) {
            result.insert(0, 1, '1');
        }
        return result;
    }
};