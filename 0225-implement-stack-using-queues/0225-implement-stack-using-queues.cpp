class MyStack {
public:
    void push(int x) {
#if 1
        elements.push(x);
        for (int i = 0; i < elements.size() - 1; ++i) {
            elements.push(elements.front());
            elements.pop();
        }
#else
        queue<int> temp{};
        temp.push(x);
        while (!elements.empty()) {
            temp.push(elements.front());
            elements.pop();
        }
        swap(temp, elements);
#endif
    }

    int pop() {
        const int ret = top();
        elements.pop();
        return ret;
    }

    int top() { return elements.front(); }

    bool empty() { return elements.empty(); }

private:
    queue<int> elements{};
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */