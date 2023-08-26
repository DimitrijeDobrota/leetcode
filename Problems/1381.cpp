class CustomStack {
    vector<int> st;
    int size = 0;

  public:
    CustomStack(int maxSize) : st(maxSize) {}

    void push(int x) {
        if (size == st.size()) return;
        st[size++] = x;
    }

    int pop() {
        if (size == 0) return -1;
        return st[--size];
    }

    void increment(int k, int val) {
        for (int i = 0; i < min(k, size); i++)
            st[i] += val;
    }
};
