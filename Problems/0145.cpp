class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    if (!root) return {};

    vector<int> res;
    unordered_set<TreeNode *> s;
    stack<TreeNode *> st;

    while (root) {
      st.push(root);
      root = root->left;
    }

    while (!st.empty()) {
      TreeNode *root = st.top();
      st.pop();
      if (!s.count(root)) {
        s.insert(root);
        st.push(root);
        root = root->right;
        while (root) {
          st.push(root);
          root = root->left;
        }
      } else {
        res.push_back(root->val);
      }
    }

    return res;
  }
};
