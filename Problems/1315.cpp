class Solution {
  public:
    int sumEvenGrandparent(TreeNode *root) {
        stack<TreeNode *> st;
        int sum = 0;

        st.push(root);
        while (!st.empty()) {
            TreeNode *root = st.top();
            st.pop();

            if (root->left) {
                st.push(root->left);
                if (root->val % 2 == 0) {
                    if (root->left->left) sum += root->left->left->val;
                    if (root->left->right) sum += root->left->right->val;
                }
            }

            if (root->right) {
                st.push(root->right);
                if (root->val % 2 == 0) {
                    if (root->right->left) sum += root->right->left->val;
                    if (root->right->right) sum += root->right->right->val;
                }
            }
        }

        return sum;
    }
};
