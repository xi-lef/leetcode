/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(const TreeNode* root) {
        vector<int> answer{};
        const TreeNode* cur = root;
        stack<const TreeNode*> s{};
        while (cur) {
            answer.push_back(cur->val);
            if (cur->left) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = cur->right;
                while (!cur && !s.empty()) {
                    cur = s.top()->right;
                    s.pop();
                }
                if (!cur)
                    break;
            }
        }
        return answer;
    }
};