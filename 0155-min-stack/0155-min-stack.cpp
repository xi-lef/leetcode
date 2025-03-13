class MinStack {
public:
    void push(int val) {
        stack.push_back(val);
        mins.push_back(mins.empty() ? val : min(mins.back(), val));
    }

    void pop() {
        stack.pop_back();
        mins.pop_back();
    }

    int top() { return stack.back(); }

    int getMin() { return mins.back(); }

private:
    vector<int> stack{};
    vector<int> mins{};
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */