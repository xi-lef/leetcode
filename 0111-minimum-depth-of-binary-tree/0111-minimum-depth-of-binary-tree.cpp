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
    int minDepth(const TreeNode* root) {
        if (!root)
            return 0;

#if 1
        queue<pair<const TreeNode*, int>> q{{{root, 1}}};
        while (!q.empty()) {
            const auto [n, d] = q.front();
            q.pop();

            if (!n->left && !n->right)
                return d;

            if (n->left)
                q.emplace(n->left, d + 1);
            if (n->right)
                q.emplace(n->right, d + 1);
        }
        return -1;
#else
        if (!root->left) {
            if (!root->right)
                return 1;
            else
                return 1 + minDepth(root->right);
        }
        if (!root->right)
            return 1 + minDepth(root->left);
        return 1 + min(minDepth(root->left), minDepth(root->right));
#endif
    }
};