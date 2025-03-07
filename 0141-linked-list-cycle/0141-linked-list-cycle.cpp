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
    bool hasCycle(ListNode* head) {
        ListNode dummy;
        while (head) {
            if (head->next == &dummy)
                return true;
            head = exchange(head->next, &dummy);
        }
        return false;
    }
};