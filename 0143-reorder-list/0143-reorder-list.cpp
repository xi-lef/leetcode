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
    void reorderList(ListNode* head) {
        int n = 0;
        for (ListNode* i = head; i; i = i->next)
            ++n;
        if (n < 3)
            return;

        ListNode* mid = head;
        for (int i = 0; i < (n + 1) / 2; ++i)
            mid = mid->next;

        ListNode* cur = mid;
        for (ListNode* next = mid->next; next;)
            next = exchange(next->next, exchange(cur, next));
        mid->next = nullptr;

        while (cur) {
            head = exchange(head->next, cur);
            cur = exchange(cur->next, head);
        }
        head->next = nullptr;
    }
};