class Solution {
public:
    vector<int> smallestSubarrays(const vector<int>& nums) {
        const int n = nums.size();
#if 1
        vector<int> last_seen(32, -1);
        int max_or = 0;
        vector<int> answer(n);
        for (int i = n - 1; i >= 0; --i) {
            const int num = nums[i];
            int last_needed = i;
            for (int j = 0, x = num, target = max_or; j < 32 && (x || target);
                 ++j) {
                if (x & 1)
                    last_seen[j] = i;
                if (target & 1)
                    last_needed = max(last_needed, last_seen[j]);
                x >>= 1;
                target >>= 1;
            }

            max_or |= num;
            answer[i] = last_needed - i + 1;
        }
        return answer;
#else
        int cur_len = 0;
        int last = n - 1;
        array<int, 32> counts{};
        vector<int> answer(n);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = 0, num = nums[i]; num && j < 32; ++j) {
                if (num & 1)
                    ++counts[j];
                num >>= 1;
            }

            while (last > i) {
                auto cpy = counts;
                bool stop = false;
                for (int j = 0, num = nums[last]; num && j < 32; ++j) {
                    if (num & 1) {
                        if (--cpy[j] == 0) {
                            stop = true;
                            break;
                        }
                    }
                    num >>= 1;
                }
                if (stop)
                    break;
                counts = cpy;
                --last;
                --cur_len;
            }
            ++cur_len;
            answer[i] = cur_len;
        }
        return answer;
#endif
    }
};