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
    ListNode* modifiedList(const vector<int>& nums, ListNode* head) {
        const unordered_set<int> set{nums.begin(), nums.end()};
        ListNode** prevnext = &head;
        for (ListNode* i = head; i; i = i->next) {
            if (set.contains(i->val))
                *prevnext = i->next;
            else
                prevnext = &i->next;
        }
        return head;
    }
};