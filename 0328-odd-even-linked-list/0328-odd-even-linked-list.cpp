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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* odd_head = nullptr;
        ListNode** odd_tailnext = &odd_head;
        ListNode* last;
        for (ListNode* i = head; i && i->next; i = i->next) {
            *odd_tailnext = i->next;
            odd_tailnext = &i->next->next;
            i->next = i->next->next;
            last = i->next ? i->next : i;
        }

        *odd_tailnext = nullptr;
        last->next = odd_head;
        return head;
    }
};