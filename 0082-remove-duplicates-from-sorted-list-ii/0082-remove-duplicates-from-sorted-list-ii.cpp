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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode** prevnext = &head;
        for (ListNode* i = head; i && i->next; i = i->next) {
            bool duplicate = false;
            while (i->next && i->val == i->next->val) {
                duplicate = true;
                i->next = i->next->next;
            }
            if (duplicate)
                *prevnext = i->next;
            else
                prevnext = &i->next;
        }
        return head;
    }
};