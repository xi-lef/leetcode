#if 1
// Fast, simple (and memory-safe)
class Trie {
public:
    void insert(string word) {
        unique_ptr<Node>* cur = &root;
        for (const char& c : word) {
            unique_ptr<Node>& n = cur->get()->next[c - 'a'];
            if (!n)
                n = make_unique<Node>();
            cur = &n;
        }
        cur->get()->end = true;
    }

    bool search(string word) {
        unique_ptr<Node>* cur = &root;
        for (const char& c : word) {
            if (*cur && !(cur = &cur->get()->next[c - 'a']))
                return false;
        }
        return cur->get() && cur->get()->end;
    }

    bool startsWith(string prefix) {
        unique_ptr<Node>* cur = &root;
        for (const char& c : prefix) {
            if (*cur && !(cur = &cur->get()->next[c - 'a']))
                return false;
        }
        return cur->get();
    }

private:
    struct Node {
        bool end{false};
        unique_ptr<Node> next[26]{};
    };
    unique_ptr<Node> root{make_unique<Node>()};
};
#else
// "Clean", nice, extendable
class Trie {
public:
    Trie() : root(make_unique<Node>()) {}

    void insert(string word) {
        unique_ptr<Node>* cur = &root;
        for (const char& c : word) {
            Node& node = *cur->get();
            if (node.contains(c)) {
                cur = &node.get(c);
            } else {
                cur = &node.insert(c);
            }
        }
        cur->get()->mark_end();
    }

    bool search(string word) {
        const unique_ptr<Node>* cur = &root;
        for (const char& c : word) {
            const Node& node = *cur->get();
            if (!node.contains(c))
                return false;
            cur = &node.get(c);
        }
        return cur->get()->is_end();
    }

    bool startsWith(string prefix) {
        const unique_ptr<Node>* cur = &root;
        for (const char& c : prefix) {
            const Node& node = *cur->get();
            if (!node.contains(c))
                return false;
            cur = &node.get(c);
        }
        return static_cast<bool>(*cur);
    }

private:
    class Node {
    public:
        Node() = default;
        Node(bool end) : end(end) {}
        ~Node() { delete nodes; }

        bool contains(char i) const { return valid[i]; }
        unique_ptr<Node>& get(char i) { return nodes->at(i); }
        const unique_ptr<Node>& get(char i) const { return nodes->at(i); }
        unique_ptr<Node>& insert(char i) {
            valid[i] = true;
            return (*nodes)[i] = make_unique<Node>();
        }
        void mark_end() { end = true; }
        bool is_end() const { return end; }

    private:
        bool end{false};
        vector<bool> valid = vector(256, false);
        unordered_map<char, unique_ptr<Node>>* nodes{
            new unordered_map<char, unique_ptr<Node>>{}};
    };

    unique_ptr<Node> root;
};
#endif

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */