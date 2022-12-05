class Solution {
public:
  int diameterOfBinaryTree(TreeNode *root) {
    unordered_map<TreeNode *, int> um;
    stack<TreeNode *> st;
    int res = 0;

    while (root) {
      st.push(root);
      root = root->left;
    }

    while (!st.empty()) {
      TreeNode *root = st.top();
      st.pop();
      if (um.find(root) == um.end()) {
        um.insert({root, 1});
        st.push(root);
        root = root->right;
        while (root) {
          st.push(root);
          root = root->left;
        }
      } else {
        if (!root->left && !root->right) continue;
        int l = um[root->left];
        int r = um[root->right];
        res = max(l + r, res);
        um[root] = 1 + max(l, r);
      }
    }

    return res;
  }
};
