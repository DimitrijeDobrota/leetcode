class Solution {
  string preorder(TreeNode *root, bool left) {
    if (!root) return "";

    string res;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *root = st.top();
      st.pop();
      if (!root) {
        res += "-";
        continue;
      }
      res += root->val;
      if (left) {
        st.push(root->right);
        st.push(root->left);
      } else {
        st.push(root->left);
        st.push(root->right);
      }
    }
    return res;
  }

public:
  bool isSymmetric(TreeNode *root) {
    if (!root) return false;

    return preorder(root->left, true) == preorder(root->right, false);
  }
};
