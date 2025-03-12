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
    vector<vector<int>> levelOrder(const TreeNode* root) {
        if (!root)
            return {};

        vector<vector<int>> order;
        queue<const TreeNode*> bfs{{root}};
        while (!bfs.empty()) {
            order.emplace_back();
            vector<int>& level = order.back();
            queue<const TreeNode*> next_bfs;
            while (!bfs.empty()) {
                const TreeNode* n = bfs.front();
                bfs.pop();

                level.push_back(n->val);

                if (n->left)
                    next_bfs.push(n->left);
                if (n->right)
                    next_bfs.push(n->right);
            }
            bfs = move(next_bfs);
        }
        return order;
    }
};