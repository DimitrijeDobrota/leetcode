class Solution {
  public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        int n = pushed.size(), m = popped.size();
        int i = 0, j = 0;
        stack<int> st;

        while (i < n || j < m) {
            if (st.empty()) {
                if (i < n)
                    st.push(pushed[i++]);
                else
                    return false;
            } else {
                if (st.top() == popped[j])
                    st.pop(), j++;
                else if (i < n)
                    st.push(pushed[i++]);
                else
                    return false;
            }
        }

        return true;
    }
};
