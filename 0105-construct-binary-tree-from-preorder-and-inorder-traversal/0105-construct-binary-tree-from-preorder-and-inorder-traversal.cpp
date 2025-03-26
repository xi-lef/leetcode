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
    unordered_set<int> added{};
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;
        const int pre = preorder.front();
        preorder.erase(preorder.begin());
        TreeNode* cur = new TreeNode{pre};
        added.insert(pre);

        if (pre != inorder.front())
            cur->left = buildTree(preorder, inorder);
        inorder.erase(inorder.begin());
        if (!added.contains(inorder.front()))
            cur->right = buildTree(preorder, inorder);
        return cur;
    }
};