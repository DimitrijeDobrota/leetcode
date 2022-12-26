class Solution {
public:
  int getMinimumDifference(TreeNode *root) {
    stack<TreeNode *> st;
    int res = INT_MAX;
    TreeNode *prev = new TreeNode(INT_MAX);
    while (true) {
      while (root) {
        st.push(root);
        root = root->left;
      }
      if (st.empty()) break;
      root = st.top();
      st.pop();
      res = min(res, abs(prev->val - root->val));
      prev = root;
      root = root->right;
    }
    return res;
  }
};
