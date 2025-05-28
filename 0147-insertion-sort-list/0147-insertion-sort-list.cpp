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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* answer = nullptr;
        ListNode** prevnext = &answer;
        while (head) {
            while (*prevnext && (*prevnext)->val < head->val)
                prevnext = &((*prevnext)->next);
            head = exchange(head->next, exchange(*prevnext, head));
            if (head && (*prevnext)->val > head->val)
                prevnext = &answer;
        }
        return answer;
    }
};