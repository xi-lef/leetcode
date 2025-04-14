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
    bool isPalindrome(ListNode* head) {
        bool odd = false;
        ListNode* mid = head;
        ListNode* tail;
        ListNode* prev;
        for (ListNode* i = head; i; i = i->next) {
            if (odd) {
                prev = mid;
                mid = mid->next;
            }
            odd = !odd;
            tail = i;
        }

        while (mid) {
            mid = exchange(mid->next, exchange(prev, mid));
        }

        prev = nullptr;
        bool ans = true;
        while (head != tail && head->next != tail) {
            if (head->val != tail->val)
                ans = false;
            head = head->next;
            tail = exchange(tail->next, exchange(prev, tail));
        }
        tail->next = prev;
        return ans && head->val == tail->val;
    }
};