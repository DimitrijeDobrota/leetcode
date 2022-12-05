class Solution {
public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> st;

    while (true) {
      while (root) {
        st.push(root);
        root = root->left;
      }

      if (!st.empty()) {
        root = st.top();
        st.pop();
        res.push_back(root->val);
        root = root->right;
      } else
        return res;
    }

    return res;
  }
};
