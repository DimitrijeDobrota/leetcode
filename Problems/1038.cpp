class Solution {
  public:
    TreeNode *bstToGst(TreeNode *root) {
        TreeNode *head = root;
        stack<TreeNode *> st;
        int sum = 0;
        while (true) {
            while (root) {
                st.push(root);
                root = root->right;
            }
            if (st.empty()) break;
            root = st.top(), st.pop();
            sum = root->val += sum;
            root = root->left;
        }
        return head;
    }
};
