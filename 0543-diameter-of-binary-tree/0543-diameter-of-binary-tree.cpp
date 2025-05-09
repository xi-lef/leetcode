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
    int height(TreeNode* root) {
        if (!root)
            return 0;

        static unordered_map<TreeNode*, int> memo;
        const auto f = memo.find(root);
        if (f != memo.end()) return f->second;

        const int h = 1 + max(height(root->left), height(root->right));
        return memo[root] = h;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        return max(height(root->left) + height(root->right),
                   max(diameterOfBinaryTree(root->left),
                       diameterOfBinaryTree(root->right)));
    }
};