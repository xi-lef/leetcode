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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* last_zero = head;
        int sum = 0;
        for (ListNode* i = head->next; i; i = i->next) {
            sum += i->val;
            if (i->val == 0) {
                last_zero->val = sum;
                if (!i->next) {
                    last_zero->next = nullptr;
                    break;
                }
                last_zero->next = i;
                last_zero = i;
                sum = 0;
            }
        }
        return head;
    }
};