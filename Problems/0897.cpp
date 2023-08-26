class Solution {
  public:
    TreeNode *increasingBST(TreeNode *root) {
        TreeNode *head, *tmp;
        tmp = head = new TreeNode();
        stack<TreeNode *> st;
        while (true) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            if (st.empty()) break;
            root = st.top();
            st.pop();
            tmp = tmp->right = root;
            tmp->left = nullptr;
            root = root->right;
        }
        return head->right;
    }
};
