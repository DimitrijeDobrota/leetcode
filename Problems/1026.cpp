class Solution {
public:
  int maxAncestorDiff(TreeNode *root) {
    if (!root) return 0;
    int res = 0;
    stack<pair<TreeNode *, pair<int, int>>> st;
    st.push({
        root, {root->val, root->val}
    });
    while (!st.empty()) {
      TreeNode *root = st.top().first;
      int maxi = st.top().second.first;
      int mini = st.top().second.second;
      st.pop();
      res = max(res, abs(maxi - root->val));
      res = max(res, abs(mini - root->val));
      if (root->left)
        st.push({
            root->left,
            {max(maxi, root->left->val), min(mini, root->left->val)}
        });
      if (root->right)
        st.push({
            root->right,
            {max(maxi, root->right->val), min(mini, root->right->val)}
        });
    }
    return res;
  }
};
