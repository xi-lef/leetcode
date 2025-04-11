/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(const TreeNode* root) {
        if (!root)
            return "N";
        return to_string(root->val) + "," + serialize(root->left) + "," +
               serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return deserialize(string_view{data}).first;
    }

    pair<TreeNode*, int> deserialize(string_view data) {
        if (data.starts_with("N"))
            return {nullptr, 1};

        int value;
        const char* const begin = data.data();
        const char* const end = from_chars(begin, &data.back(), value).ptr + 1;
        TreeNode* node = new TreeNode(value);
        data.remove_prefix(end - begin);

        const auto [lnode, lpos] = deserialize(data);
        node->left = lnode;
        data.remove_prefix(lpos + 1);

        const auto [rnode, rpos] = deserialize(data);
        node->right = rnode;
        data.remove_prefix(rpos);
        return {node, end - begin + lpos + 1 + rpos};
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));