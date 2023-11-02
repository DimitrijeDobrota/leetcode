class Solution {
    typedef tuple<int, int> tii;

  public:
    int averageOfSubtree(const TreeNode *root) const {
        unordered_map<const TreeNode *, tii> um;
        stack<const TreeNode *> st;
        int count = 0;
        st.push(root);
        while (!st.empty()) {
            if (st.top() != nullptr) {
                const TreeNode *root = st.top();
                st.push(nullptr);
                if (root->left) st.push(root->left);
                if (root->right) st.push(root->right);
                continue;
            }
            st.pop();
            const TreeNode *root = st.top();
            st.pop();

            tii left = um[root->left], right = um[root->right];
            um[root] = {root->val + get<0>(left) + get<0>(right), 1 + get<1>(left) + get<1>(right)};
            if (get<0>(um[root]) / get<1>(um[root]) == root->val) count++;
        }
        return count;
    }
};
