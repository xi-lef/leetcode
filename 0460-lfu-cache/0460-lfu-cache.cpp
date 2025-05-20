class LFUCache {
public:
    LFUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        // cout << "getting " << key << endl;
        if (!cache.contains(key))
            return -1;
        return access_key(key);
    }

    void put(int key, int value) {
        // cout << "putting " << key << " (size " << cache.size() << ")";
        if (cache.contains(key)) {
            // cout << " found";
            access_key(key) = value;
        } else {
            if (cache.size() == capacity) {
                const auto& bucket = buckets.begin();
                auto& ll = bucket->second;
                const auto& rm = get<0>(ll.front());
                // cout << " replacing " << rm;
                cache.erase(rm);
                if (ll.size() == 1)
                    buckets.erase(bucket);
                else
                    ll.pop_front();
            }
            auto& b1 = buckets[1];
            cache[key] = b1.emplace(b1.end(), key, value, 1);
        }
        // cout << endl;
    }

private:
    int& access_key(int key) {
        auto& it = cache[key];
        int& count = get<2>(*it);
        auto& old_bucket = buckets[count];
        auto& new_bucket = buckets[++count];
        new_bucket.splice(new_bucket.end(), old_bucket, it);
        if (old_bucket.empty())
            buckets.erase(count - 1);
        return get<1>(*it);
    }

    const int capacity;
    map<int, list<tuple<int, int, int>>> buckets{};
    unordered_map<int, decltype(buckets)::mapped_type::iterator> cache{};
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */