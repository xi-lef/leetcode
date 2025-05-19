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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode** prevnext = &head;
        ListNode* cur = head;
        ListNode* prev = nullptr;
        for (int i = 0; i < left; ++i) {
            if (i)
                prevnext = &prev->next;
            prev = cur;
            cur = cur->next;
        }
        ListNode* const first = prev;

        for (int i = 0; i < right - left; ++i)
            cur = exchange(cur->next, exchange(prev, cur));
        *prevnext = prev;
        if (first)
            first->next = cur;
        return head;
    }
};