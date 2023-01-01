class Solution {
public:
  bool isBalanced(TreeNode *root) {
    if (!root) return true;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *root = st.top();
      if (root == nullptr) {
        st.pop(), root = st.top(), st.pop();
        int left = root->left ? root->left->val : 0;
        int right = root->right ? root->right->val : 0;
        if (abs(right - left) > 1) return false;
        root->val = max(left, right) + 1;
        continue;
      }
      st.push(nullptr);
      if (root->left) st.push(root->left);
      if (root->right) st.push(root->right);
    }
    return true;
  }
};
