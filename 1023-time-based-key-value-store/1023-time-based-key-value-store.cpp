class TimeMap {
public:
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto& m = store[key];
        auto lb = m.lower_bound(timestamp);
        if (lb == m.end()) {
            if (m.empty())
                return {};
            return (--m.end())->second;
        }
        if (lb->first == timestamp)
            return lb->second;
        if (lb == m.begin())
            return {};
        return (--lb)->second;
    }

private:
    unordered_map<string, map<int, string>> store{};
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */