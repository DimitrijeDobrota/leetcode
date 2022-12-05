class Solution {
  vector<int> sequence(TreeNode *root) {
    if (!root) return {};

    vector<int> res;
    stack<TreeNode *> st;

    st.push(root);
    while (!st.empty()) {
      TreeNode *root = st.top();
      st.pop();
      if (!root->left && !root->right) {
        res.push_back(root->val);
        continue;
      }
      if (root->left) st.push(root->left);
      if (root->right) st.push(root->right);
    }

    return res;
  }

public:
  bool leafSimilar(TreeNode *root1, TreeNode *root2) {
    return sequence(root1) == sequence(root2);
  }
};
