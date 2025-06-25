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
    ListNode* removeNodes(ListNode* head) {
#if 1
        ListNode* prev = nullptr;
        ListNode* cur = head;
        for (;;) {
            // Find local maximum (i.e., node with a smaller node following)
            while (cur->next && cur->next->val > cur->val)
                cur = cur->next;

            // "Remove" previous nodes that are smaller (mono-decreasing stack)
            while (prev && prev->val < cur->val)
                prev = prev->next;
            if (!cur->next) {
                cur->next = prev;
                break;
            }
            cur = exchange(cur->next, exchange(prev, cur));
        }

        // Reverse list so order is correct
        prev = nullptr;
        while (cur)
            cur = exchange(cur->next, exchange(prev, cur));
        return prev;
#else
        if (!head)
            return nullptr;
        while (head->next && head->next->val > head->val)
            head = head->next;

        ListNode* rec = removeNodes(head->next);
        if (rec && rec->val > head->val)
            return rec;
        head->next = rec;
        return head;
#endif
    }
};