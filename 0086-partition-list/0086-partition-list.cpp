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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lt;
        ListNode* gteq;
        ListNode** lt_pn = &lt;
        ListNode** gteq_pn = &gteq;
        while (head) {
            if (head->val < x) {
                *lt_pn = head;
                lt_pn = &head->next;
            } else {
                *gteq_pn = head;
                gteq_pn = &head->next;
            }
            head = head->next;
        }
        *lt_pn = gteq;
        *gteq_pn = nullptr;
        return lt;
    }
};