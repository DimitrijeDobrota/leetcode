class Solution {
  public:
    int maxPathSum(TreeNode *root) {
        if (!root) return 0;
        int res = INT_MIN;

        unordered_set<TreeNode *> us;
        stack<TreeNode *> st;
        while (root) {
            st.push(root);
            root = root->left;
        }
        while (!st.empty()) {
            TreeNode *root = st.top();
            st.pop();

            if (us.find(root) == us.end()) {
                st.push(root);
                us.insert(root);
                root = root->right;
                while (root) {
                    st.push(root);
                    root = root->left;
                }
            } else {
                int opt = 0, sum = 0;
                if (root->left) {
                    opt = max(opt, root->left->val), sum += root->left->val;
                };
                if (root->right) {
                    opt = max(opt, root->right->val), sum += root->right->val;
                };
                res = max(res, root->val + sum);
                root->val = max(root->val, root->val + opt);
                res = max(res, root->val);
                continue;
            }
        }
        return res;
    }
};
