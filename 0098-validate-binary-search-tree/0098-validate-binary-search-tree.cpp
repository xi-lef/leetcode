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
    bool isValidBST(const TreeNode* root) {
        return check(root, numeric_limits<long>::min(),
                     numeric_limits<long>::max());
    }

    bool check(const TreeNode* cur, long min, long max) {
        if (!cur)
            return true;

        if (cur->val <= min || cur->val >= max) {
            return false;
        }
        return check(cur->left, min, cur->val) &&
               check(cur->right, cur->val, max);
    }
};