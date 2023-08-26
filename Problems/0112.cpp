class Solution {
  public:
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) return false;

        stack<pair<TreeNode *, int>> st;
        st.push(make_pair(root, 0));
        while (!st.empty()) {
            TreeNode *root = st.top().first;
            int val = st.top().second + root->val;
            st.pop();

            if (val == targetSum && !root->left && !root->right) return true;

            if (root->left) st.push(make_pair(root->left, val));
            if (root->right) st.push(make_pair(root->right, val));
        }
        return false;
    }
};
