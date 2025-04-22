class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool carry = true;
        for (ssize_t i = digits.size() - 1; i >= 0 && carry; --i) {
            int& digit = digits[i];
            digit += carry;
            carry = digit > 9;
            digit %= 10;
        }
        if (carry)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};