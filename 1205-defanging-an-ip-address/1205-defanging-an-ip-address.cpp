class Solution {
public:
    string defangIPaddr(string address) {
        for (size_t i = 0; i < address.size(); ++i) {
            if (address[i] == '.')
                address.replace(i++, 1, "[.]");
        }
        return address;
    }
};