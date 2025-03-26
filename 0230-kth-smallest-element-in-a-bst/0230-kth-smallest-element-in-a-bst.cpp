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
    int answer{-1};
    int kthSmallest(TreeNode* root, int k) {
        solve(root, k);
        return answer;
    }

    int solve(TreeNode* root, int k) {
        if (!root || answer != -1)
            return 0;
        const int count = solve(root->left, k) + 1;
        if (count == k) {
            answer = root->val;
            return count;
        }
        return count + solve(root->right, k - count);
    }
};