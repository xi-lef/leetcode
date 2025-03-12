/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(const Node* node) {
        if (!node)
            return nullptr;
        const auto n = nodes.find(node->val);
        if (n != nodes.end())
            return n->second;

        Node* copy =
            nodes.emplace(node->val, new Node(node->val)).first->second;
        for (const Node* n : node->neighbors) {
            copy->neighbors.push_back(cloneGraph(n));
        }
        return copy;
    }

private:
    unordered_map<int, Node*> nodes;
};