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
    TreeNode* sortedArrayToBST(const vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size());
    }

    TreeNode* sortedArrayToBST(const vector<int>& nums, int start, int end) {
        if (start == end)
            return nullptr;
        if (start == end - 1)
            return new TreeNode(nums[start]);

        const int mid = (start + end) / 2;
        return new TreeNode(nums[mid], sortedArrayToBST(nums, start, mid),
                            sortedArrayToBST(nums, mid + 1, end));
    }
};