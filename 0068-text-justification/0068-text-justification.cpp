class Solution {
public:
    vector<string> fullJustify(const vector<string>& words, int maxWidth) {
        const int n = words.size();
        vector<string> answer{};
        int start = 0;
        int len = 0;
        for (int i = 0; i < n + 1; ++i) {
            const int word_len = (i == n) ? maxWidth + 1 : words[i].size();
            const int inc = (start != i) + word_len;
            if (len + inc <= maxWidth) {
                len += inc;
                continue;
            }

            // Didn't fit: put words from "start" to "i" into one line.
            const int num_words = i - start;
            const int extra_spaces = maxWidth - len;
            const bool single_or_last = num_words == 1 || i == n;
            int spaces_per_word = 1;
            if (!single_or_last)
                spaces_per_word += extra_spaces / (num_words - 1);
            int left_extra_spaces =
                single_or_last ? 0 : extra_spaces % (num_words - 1);

            string line{};
            for (int j = start; j < i; ++j) {
                line += words[j];
                if (j < i - 1)
                    line += string(
                        spaces_per_word + bool{left_extra_spaces-- > 0}, ' ');
            }
            if (single_or_last)
                line += string(extra_spaces, ' ');

            answer.push_back(move(line));
            start = i;
            len = word_len;
        }
        return answer;
    }
};