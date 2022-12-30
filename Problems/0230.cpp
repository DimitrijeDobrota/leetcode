class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    stack<TreeNode *> st;
    while (true) {
      while (root) {
        st.push(root);
        root = root->left;
      }
      if (st.empty()) break;
      root = st.top(), st.pop();
      if (!--k) return root->val;
      root = root->right;
    }
    return -1;
  }
};
