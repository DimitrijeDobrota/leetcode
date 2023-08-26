class Solution {
  public:
    TreeNode *pruneTree(TreeNode *root) {
        TreeNode dummy(1, root, nullptr);
        unordered_set<TreeNode *> has;
        stack<TreeNode *> st;
        st.push(&dummy);
        while (!st.empty()) {
            TreeNode *root = st.top();
            if (!root) {
                st.pop();
                root = st.top(), st.pop();
                if (has.count(root->left))
                    has.insert(root);
                else
                    root->left = nullptr;

                if (has.count(root->right))
                    has.insert(root);
                else
                    root->right = nullptr;

                if (root->val == 1) has.insert(root);
                continue;
            }
            st.push(nullptr);
            if (root->left) st.push(root->left);
            if (root->right) st.push(root->right);
        }
        return dummy.left;
    }
};
