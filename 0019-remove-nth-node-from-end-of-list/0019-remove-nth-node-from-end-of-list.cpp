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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        while (head) {
            head = exchange(head->next, exchange(prev, head));
        }
        head = prev;

        prev = nullptr;
        while (head) {
            if (--n == 0) {
                head = head->next;
                if (!head)
                    break;
            }
            head = exchange(head->next, exchange(prev, head));
        }
        return prev;
    }
};