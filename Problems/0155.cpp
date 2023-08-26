class MinStack {
    stack<pair<int, int>> st;

  public:
    MinStack() {}
    void push(int val) { st.push({val, !st.size() ? val : min(val, st.top().second)}); }
    void pop() { st.pop(); }
    int top() { return st.top().first; }
    int getMin() { return st.top().second; }
};
