class Solution {
public:
  int sumOfLeftLeaves(TreeNode *root) {
    if (!root) return 0;

    int res = 0;
    stack<TreeNode *> st;

    st.push(root);
    while (!st.empty()) {
      TreeNode *root = st.top();
      st.pop();
      if (root->left) {
        if (!root->left->left && !root->left->right)
          res += root->left->val;
        else
          st.push(root->left);
      }
      if (root->right) st.push(root->right);
    }
    return res;
  }
};
