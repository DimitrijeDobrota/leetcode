class MinStack {
    std::vector<std::pair<int, int>> stack;

public:
    MinStack() = default;
    
    void push(int value) {
        const auto min = !std::empty(stack)
                       ? std::min(stack.back().second, value)
                       : value;
        stack.emplace_back(value, min);
    }
    
    void pop() {
       stack.pop_back(); 
    }
    
    int top() const {
        return stack.back().first; 
    }
    
    int getMin() const {
        return stack.back().second; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */