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
    vector<int> rightSideView(TreeNode* root, int skip = 0) {
        if (!root)
            return {};
        vector<int> answer{};
        if (!skip)
            answer.push_back(root->val);

        skip = max(0, skip - 1);
        vector<int> right = rightSideView(root->right, skip);
        vector<int> left = rightSideView(root->left, skip + right.size());
        ranges::move(right, back_inserter(answer));
        ranges::move(left, back_inserter(answer));
        return answer;
    }
};