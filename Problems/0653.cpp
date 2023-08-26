class Solution {
    TreeNode *root;
    TreeNode *find(int k) {
        TreeNode *t = root;
        while (t && t->val != k)
            t = t->val > k ? t->left : t->right;
        return t;
    }

  public:
    bool findTarget(TreeNode *root, int k) {
        stack<TreeNode *> st;
        st.push(this->root = root);
        while (!st.empty()) {
            TreeNode *t, *root = st.top();
            st.pop();
            while (root) {
                if ((t = find(k - root->val)) && t != root) return true;
                if (root->right) st.push(root->right);
                root = root->left;
            }
        }
        return false;
    }
};
