class Solution {
  public:
    TreeNode *trimBST(TreeNode *root, int low, int high) {
        if (!root) return nullptr;
        while (root) {
            if (root->val < low)
                root = root->right;
            else if (root->val > high)
                root = root->left;
            else
                break;
        }
        stack<pair<TreeNode *, TreeNode **>> st;
        TreeNode *head = root, **link = nullptr;
        while (true) {
            while (root) {
                if (root->val < low)
                    root = *link = root->right;
                else if (root->val > high)
                    root = *link = root->left;
                else {
                    if (root->right) st.push({root->right, &root->right});
                    link = &root->left;
                    root = root->left;
                }
            }
            if (st.empty()) break;
            root = st.top().first;
            link = st.top().second;
            st.pop();
        }
        return head;
    }
};
