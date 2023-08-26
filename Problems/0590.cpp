class Solution {
  public:
    vector<int> postorder(Node *root) {
        if (!root) return {};
        vector<int> res;
        stack<Node *> st;
        st.push(root);
        while (!st.empty()) {
            Node *root = st.top();
            st.pop();
            for (Node *c : root->children)
                st.push(c);
            res.push_back(root->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
