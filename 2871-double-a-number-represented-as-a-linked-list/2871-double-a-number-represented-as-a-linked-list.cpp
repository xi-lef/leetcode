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
    ListNode* doubleIt(ListNode* head) {
        const int carry = dub(head);
        if (carry) {
            ListNode* n = new ListNode(carry, head);
            head = n;
        }
        return head;
    }

private:
    int dub(ListNode* head) {
        if (!head)
            return 0;

        const int val = head->val * 2 + dub(head->next);
        head->val = val % 10;
        return val / 10;
    }
};