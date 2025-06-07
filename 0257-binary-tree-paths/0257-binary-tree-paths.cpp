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
    vector<string> binaryTreePaths(TreeNode* root) {
        string s{};
        vector<string> answer{};
        solve(root, answer, s);
        return answer;
    }

private:
    void solve(TreeNode* node, vector<string>& answer, string& s) {
        const size_t n = s.size();
        if (n > 0)
            s += "->";
        s += to_string(node->val);

        if (!node->left && !node->right)
            answer.push_back(s);
        if (node->left)
            solve(node->left, answer, s);
        if (node->right)
            solve(node->right, answer, s);
        s.erase(n);
    }
};