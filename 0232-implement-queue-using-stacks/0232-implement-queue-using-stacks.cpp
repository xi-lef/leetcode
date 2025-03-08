class MyQueue {
public:
    void push(int x) {
        while (!b.empty()) {
            a.push(b.top());
            b.pop();
        }
        a.push(x);
    }

    int pop() {
        const int ret = peek();
        b.pop();
        return ret;
    }

    int peek() {
        while (!a.empty()) {
            b.push(a.top());
            a.pop();
        }
        return b.top();
    }

    bool empty() {
        return a.empty() && b.empty();
    }

private:
    stack<int> a, b;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */