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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool carry = false;
        ListNode* answer;
        ListNode** prev_next = &answer;
        while (l1 || l2 || carry) {
            const int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum > 9;
            ListNode* n = new ListNode(sum % 10);

            *prev_next = n;
            prev_next = &n->next;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        return answer;
    }
};