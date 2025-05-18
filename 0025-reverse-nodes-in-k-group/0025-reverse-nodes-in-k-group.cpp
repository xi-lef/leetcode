/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
#if 1
        int n = 0;
        for (ListNode* i = head; i; i = i->next)
            ++n;

        ListNode** prevnext = &head;
        for (int i = 0; i < n / k; ++i) {
            ListNode* const first = *prevnext;

            ListNode* cur = first->next;
            ListNode* prev = first;
            for (int j = 1; j < k; ++j) {
                cur = exchange(cur->next, exchange(prev, cur));
            }

            first->next = cur;
            *prevnext = prev;
            prevnext = &first->next;
        }
        return head;
#else
        ListNode** prevnext = &head;
        ListNode* node = head;
        while (node) {
            ListNode* next_node;
            for (int i = 0; i < k; ++i) {
                ListNode* last = node;
                for (int j = i; j < k - 1; ++j) {
                    last = last->next;
                    if (!last)
                        return head;
                }
                *prevnext = last;
                prevnext = &last->next;
                if (i == 0)
                    next_node = last->next;
            }
            *prevnext = node = next_node;
        }
        return head;
#endif
    }
};