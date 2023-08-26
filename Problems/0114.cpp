class Solution {
  public:
    void flatten(TreeNode *root) {
        TreeNode *crnt = new TreeNode(-1);
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *root = st.top();
            st.pop();
            crnt->right = root;
            while (root) {
                crnt = root;
                if (root->right) st.push(root->right);

                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }
        }
    }
};
