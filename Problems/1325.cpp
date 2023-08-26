class Solution {
  public:
    TreeNode *removeLeafNodes(TreeNode *root, int target) {
        TreeNode dummy(-1, root, nullptr);
        unordered_map<TreeNode *, TreeNode *> um = {{root, &dummy}};
        stack<TreeNode *> st({root});
        while (!st.empty()) {
            TreeNode *root = st.top();
            if (root->val < 0) {
                st.pop();
                root->val = -root->val;
                if (!root->left && !root->right && root->val == target) {
                    TreeNode *parent = um[root];
                    (parent->left == root ? parent->left : parent->right) = nullptr;
                }
                continue;
            }
            root->val = -root->val;
            if (root->left) {
                um[root->left] = root;
                st.push(root->left);
            }
            if (root->right) {
                um[root->right] = root;
                st.push(root->right);
            }
        }
        return dummy.left;
    }
};
