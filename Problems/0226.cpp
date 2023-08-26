class Solution {
  public:
    TreeNode *invertTree(TreeNode *root) {
        if (!root) return nullptr;

        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *root = st.top();
            st.pop();
            swap(root->left, root->right);
            if (root->left) st.push(root->left);
            if (root->right) st.push(root->right);
        }
        return root;
    }
};
