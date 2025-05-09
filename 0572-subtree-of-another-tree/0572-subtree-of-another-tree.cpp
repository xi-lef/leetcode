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
    bool isSubtree(TreeNode* root, TreeNode* subRoot, bool found = false) {
        if (!root && !subRoot)
            return true;
        if (!root || !subRoot)
            return false;
        if (root->val == subRoot->val &&
            isSubtree(root->left, subRoot->left, true) &&
            isSubtree(root->right, subRoot->right, true))
            return true;
        return !found && (isSubtree(root->left, subRoot) ||
                          isSubtree(root->right, subRoot));
    }
};