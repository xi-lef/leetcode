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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = slow;
        slow = slow->next;
        prev->next = nullptr;
        while (slow)
            slow = exchange(slow->next, exchange(prev, slow));

        ListNode* next = nullptr;
        int best = 0;
        while (prev) {
            best = max(best, prev->val + head->val);
            // restore list
            prev = exchange(prev->next, exchange(next, prev));
            head = head->next;
        }
        return best;
    }
};