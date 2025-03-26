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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        const auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> queue{};

        for (const auto& n : lists) {
            if (n)
                queue.push(n);
        }

        ListNode* head = nullptr;
        ListNode* tail;
        while (!queue.empty()) {
            ListNode* n = queue.top();
            queue.pop();
            if (n->next)
                queue.push(n->next);

            if (!head) {
                head = tail = n;
            } else {
                tail = tail->next = n;
            }
        }

        return head;
    }
};