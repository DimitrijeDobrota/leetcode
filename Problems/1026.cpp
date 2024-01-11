class Solution {
  public:
    int maxAncestorDiff(TreeNode *root) {
        if (!root) return 0;
        int res = 0;
        stack<tuple<TreeNode *, int, int>> st;
        st.push({root, root->val, root->val});
        while (!st.empty()) {
            auto [root, maxi, mini] = st.top();
            st.pop();
            res = max({res, abs(maxi - root->val), abs(mini - root->val)});
            maxi = max(maxi, root->val), mini = min(mini, root->val);
            if (root->left) st.push({root->left, maxi, mini});
            if (root->right) st.push({root->right, maxi, mini});
        }
        return res;
    }
};
