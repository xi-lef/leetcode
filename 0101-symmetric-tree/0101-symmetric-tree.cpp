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
    bool isSymmetric(const TreeNode* root) {
        queue<const TreeNode*> left{{root->left}}, right{{root->right}};
        while (!left.empty() && !right.empty()) {
            const TreeNode* const l = left.front();
            left.pop();
            const TreeNode* const r = right.front();
            right.pop();

            if (!l && !r)
                continue;
            if (!l || !r || l->val != r->val)
                return false;

            left.push(l->left);
            left.push(l->right);
            right.push(r->right);
            right.push(r->left);
        }
        return left.empty() && right.empty();
    }
};