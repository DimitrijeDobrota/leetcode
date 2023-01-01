class Solution {
public:
  int findSecondMinimumValue(TreeNode *root) {
    if (!root) return -1;
    int val = root->val;
    long long res = LONG_MAX;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *root = st.top();
      st.pop();
      if (!root->left) continue;
      int m = max(root->left->val, root->right->val);
      if (m != val) res = min(res, (long long)m);
      if (root->left->val == val) st.push(root->left);
      if (root->right->val == val) st.push(root->right);
    }

    return res != LONG_MAX ? res : -1;
  }
};
