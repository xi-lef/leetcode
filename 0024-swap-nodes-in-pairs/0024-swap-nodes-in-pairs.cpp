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
    ListNode* swapPairs(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode* a = head;
        ListNode* b = head->next;
        ListNode* const answer = b ? b : a;
        ListNode* prev = nullptr;
        while (a && b) {
            if (prev) {
                prev->next = b;
            }
            prev = a;

            a->next = exchange(b->next, a);
            a = a->next;
            if (a)
                b = a->next;
        }
        return answer;
    }
};