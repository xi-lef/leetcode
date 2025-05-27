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
    ListNode* detectCycle(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        do {
            if (!slow || !fast || !fast->next)
                return nullptr;
            slow = slow->next;
            fast = fast->next->next;
        } while (slow != fast);

        ListNode* finder = head;
        while (finder != slow) {
            finder = finder->next;
            slow = slow->next;
        }
        return finder;
    }
};