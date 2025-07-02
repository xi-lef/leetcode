class RecentCounter {
public:
    int ping(int t) {
        while (!requests.empty() && t - requests.front() > 3000)
            requests.pop();

        requests.push(t);
        return requests.size();
    }

private:
    queue<int> requests{};
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */