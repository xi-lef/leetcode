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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root)
            return 0;

        const int v = root->val;
        int answer = 0;
        if (v >= low && v <= high)
            answer += v;
        if (v > low)
            answer += rangeSumBST(root->left, low, high);
        if (v < high)
            answer += rangeSumBST(root->right, low, high);
        return answer;
    }
};