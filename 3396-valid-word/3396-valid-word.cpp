class Solution {
public:
    bool isValid(const string& word) {
        const int n = word.size();
        if (n < 3)
            return false;

        bool vowel = false;
        bool consonant = false;
        for (unsigned char c : word) {
            if (isdigit(c))
                continue;

            c = tolower(c);
            if (!islower(c))
                return false;
            if ("aeiou"sv.contains(c))
                vowel = true;
            else
                consonant = true;
        }
        return vowel && consonant;
    }
};