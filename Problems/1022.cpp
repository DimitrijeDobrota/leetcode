class Solution {
public:
  int sumRootToLeaf(TreeNode *root) {
    if (!root) return 0;
    stack<pair<TreeNode *, int>> st;
    int sum = 0;

    st.push({root, 0});
    while (!st.empty()) {
      TreeNode *root = st.top().first;
      int val = (st.top().second << 1) | root->val;
      st.pop();
      if (!root->left && !root->right) {
        sum += val;
        continue;
      }
      if (root->left) st.push({root->left, val});
      if (root->right) st.push({root->right, val});
    }
    return sum;
  }
};
