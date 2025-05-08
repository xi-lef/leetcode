#include <ranges>

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
    vector<int> postorderTraversal(const TreeNode* root) {
        vector<int> answer{};
        if (!root)
            return answer;

#if 1
        stack<const TreeNode*> s{{root}};
        while (!s.empty()) {
            const auto n = s.top();
            s.pop();
            answer.push_back(n->val);

            if (n->left)
                s.push(n->left);
            if (n->right)
                s.push(n->right);
        }
        return views::reverse(answer) | ranges::to<vector>();
#else
        const TreeNode* cur = root;
        stack<pair<const TreeNode*, bool>> s{};
        while (cur) {
            if (cur->left) {
                s.emplace(cur, false);
                cur = cur->left;
            } else if (cur->right) {
                s.emplace(cur, true);
                cur = cur->right;
            } else {
                answer.push_back(cur->val);
                while (!s.empty()) {
                    bool right;
                    tie(cur, right) = s.top();
                    s.pop();
                    if (!right && cur->right) {
                        s.emplace(cur, true);
                        cur = cur->right;
                        break;
                    } else {
                        answer.push_back(cur->val);
                    }
                }
                if (s.empty())
                    break;
            }
        }
        return answer;
#endif
    }
};