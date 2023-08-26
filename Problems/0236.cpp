class Solution {
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        unordered_map<TreeNode *, TreeNode *> um;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *root = st.top();
            st.pop();
            if (root->left) {
                um.insert({root->left, root});
                st.push(root->left);
            }
            if (root->right) {
                um.insert({root->right, root});
                st.push(root->right);
            }
        }

        unordered_set<TreeNode *> ans;
        while (p) {
            ans.insert(p);
            p = um[p];
        }

        while (!ans.count(q)) {
            q = um[q];
        }

        return q;
    }
};
