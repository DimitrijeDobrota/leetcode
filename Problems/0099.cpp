class Solution {
public:
  void recoverTree(TreeNode *root) {
    stack<TreeNode *> st;
    TreeNode *head = root, *prev = new TreeNode(INT_MIN), *l1 = nullptr,
             *l2 = nullptr;
    while (true) {
      while (root) {
        st.push(root);
        root = root->left;
      }
      if (st.empty()) break;
      root = st.top(), st.pop();
      if (root->val < prev->val) {
        if (!l1) l1 = prev;
        l2 = root;
      }
      prev = root;
      root = root->right;
    }
    swap(l1->val, l2->val);
  }
};
