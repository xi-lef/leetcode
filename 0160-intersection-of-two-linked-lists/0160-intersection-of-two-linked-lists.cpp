/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int count_a = 1;
        ListNode* i;
        for (i = headA; i->next; i = i->next)
            ++count_a;
        ListNode* const last_a = i;

        int count_b = 1;
        for (i = headB; i->next; i = i->next)
            ++count_b;
        if (i != last_a)
            return nullptr;
        while (count_a > count_b) {
            --count_a;
            headA = headA->next;
        }
        while (count_b > count_a) {
            --count_b;
            headB = headB->next;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};