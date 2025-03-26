class LRUCache {
public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        if (!cache.contains(key))
            return -1;
        return get_ref(key);
    }

    void put(int key, int value) {
        if (cache.contains(key)) {
            get_ref(key) = value;
        } else {
            if (cache.size() == capacity) {
                const auto& rm = order.front();
                cache.erase(rm.first);
                order.pop_front();
            }
            cache[key] = order.emplace(order.end(), key, value);
        }
    }

private:
    int& get_ref(int key) {
        const auto& it = cache[key];
        order.splice(order.end(), order, it);
        return it->second;
    }

    const int capacity;
    list<pair<int, int>> order{};
    unordered_map<int, decltype(order)::iterator> cache{};
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */