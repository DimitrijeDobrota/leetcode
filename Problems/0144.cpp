class Solution {
public:
  vector<int> preorderTraversal(TreeNode *root) {
    if (!root) return {};

    vector<int> res;
    stack<TreeNode *> st;
    st.push(root);
    while (!st.empty()) {
      TreeNode *root = st.top();
      st.pop();
      while (root) {
        res.push_back(root->val);
        if (root->right) st.push(root->right);
        root = root->left;
      }
    }
    return res;
  }
};
