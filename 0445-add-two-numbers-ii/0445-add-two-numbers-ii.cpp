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
    bool uncarry(ListNode* l) {
        if (!l)
            return false;

        l->val += uncarry(l->next);
        const bool carry = l->val > 9;
        l->val %= 10;
        return carry;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
#if 1
        int n1 = 0;
        for (ListNode* i = l1; i; i = i->next)
            ++n1;
        int n2 = 0;
        for (ListNode* i = l2; i; i = i->next)
            ++n2;

        ListNode* result = nullptr;
        ListNode** prevnext = &result;
        while (l1 && l2) {
            int val;
            if (n1 > n2) {
                val = l1->val;
                --n1;
                l1 = l1->next;
            } else if (n2 > n1) {
                val = l2->val;
                --n2;
                l2 = l2->next;
            } else {
                val = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            *prevnext = new ListNode(val);
            prevnext = &(*prevnext)->next;
        }

        if (uncarry(result))
            result = new ListNode(1, result);
        return result;
#else
        stack<int> s1{};
        for (; l1; l1 = l1->next)
            s1.push(l1->val);
        stack<int> s2{};
        for (; l2; l2 = l2->next)
            s2.push(l2->val);

        bool carry = false;
        ListNode* result = nullptr;
        while (!s1.empty() || !s2.empty() || carry) {
            const int a = s1.empty() ? 0 : s1.top();
            const int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty())
                s1.pop();
            if (!s2.empty())
                s2.pop();

            const int digit = a + b + carry;
            result = new ListNode(digit % 10, result);
            carry = digit > 9;
        }
        return result;
#endif
    }
};