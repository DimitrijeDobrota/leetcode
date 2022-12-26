class Solution {
public:
  bool isValidBST(TreeNode *root) {
    stack<TreeNode *> st;
    long prev = LONG_MIN;
    while (true) {
      while (root) {
        st.push(root);
        root = root->left;
      }
      if (st.empty()) break;
      root = st.top();
      st.pop();
      if (root->val <= prev) return false;
      prev = root->val;
      root = root->right;
    }
    return true;
  }
};
