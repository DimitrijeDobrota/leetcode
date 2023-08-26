class Solution {
  public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int rangeSumBST(TreeNode *root, int low, int high) {
        int sum = 0;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *root = st.top();
            st.pop();
            if (root->val >= low && root->val <= high) sum += root->val;
            if (root->left && root->val > low) st.push(root->left);
            if (root->right && root->val < high) st.push(root->right);
        }
        return sum;
    }
};
