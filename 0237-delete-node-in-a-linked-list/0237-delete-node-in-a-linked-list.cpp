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
    void deleteNode(ListNode* node) {
        while (node->next) {
            node->val = node->next->val;
            if (!node->next->next)
                break;
            node = node->next;
        }
        node->next = nullptr;
        return;
    }
};