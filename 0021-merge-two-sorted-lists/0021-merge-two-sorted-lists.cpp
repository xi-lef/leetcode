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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = nullptr;
        ListNode *cur;
        while (list1 || list2) {
            ListNode **take;
            if (!list1) {
                take = &list2;
            } else if (!list2) {
                take = &list1;
            } else if (list1->val < list2->val) {
                take = &list1;
            } else {
                take = &list2;
            }

            if (!head) {
                head = *take;
                cur = head;
            } else {
                cur->next = *take;
                cur = cur->next;
            }
            *take = (*take)->next;
        }

        return head;
    }
};