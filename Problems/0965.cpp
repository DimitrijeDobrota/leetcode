class Solution {
public:
  bool isUnivalTree(TreeNode *root) {
    if (!root) return true;
    int val = root->val;
    stack<TreeNode *> st;

    st.push(root);
    while (!st.empty()) {
      TreeNode *root = st.top();
      st.pop();
      if (root->val != val) return false;
      if (root->left) st.push(root->left);
      if (root->right) st.push(root->right);
    }

    return true;
  }
};
