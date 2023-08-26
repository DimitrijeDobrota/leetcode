class Solution {
  public:
    int maxProduct(TreeNode *root) {
        if (!root) return 0;
        const unsigned int M = 1000000007;
        stack<TreeNode *> st;
        st.push(root);
        unordered_set<TreeNode *> visited;
        while (!st.empty()) {
            TreeNode *root = st.top();
            st.pop();
            if (visited.find(root) != visited.end()) {
                if (root->left) root->val += root->left->val;
                if (root->right) root->val += root->right->val;
                root->val %= M;
                continue;
            }
            st.push(root);
            visited.insert(root);
            if (root->left) st.push(root->left);
            if (root->right) st.push(root->right);
        }

        long long res = 0ll;
        int total = root->val;
        st.push(root);
        while (!st.empty()) {
            TreeNode *root = st.top();
            st.pop();
            if (root->left) {
                res = max(res, 1ll * root->left->val * (total - root->left->val));
                st.push(root->left);
            }
            if (root->right) {
                res = max(res, 1ll * root->right->val * (total - root->right->val));
                st.push(root->right);
            }
        }
        return res % M;
    }
};
