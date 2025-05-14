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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        for (ListNode* i = head; i; i = i->next)
            ++n;
        if (n == 0 || (k %= n) == 0)
            return head;

        ListNode* last;
        ListNode* kth;
        for (ListNode* i = head; i; i = i->next) {
            if (n-- == k) {
                kth = i;
                last->next = nullptr;
            }
            last = i;
        }
        last->next = head;
        return kth;
    }
};