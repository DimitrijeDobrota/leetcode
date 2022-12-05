class Solution {
public:
  vector<string> binaryTreePaths(TreeNode *root) {
    if (!root) return {};

    vector<string> res;
    stack<pair<TreeNode *, string>> st;
    st.push({root, to_string(root->val)});
    while (!st.empty()) {
      TreeNode *root = st.top().first;
      string s = st.top().second;
      st.pop();
      if (!root->left && !root->right)
        res.push_back(s);
      else {
        s += "->";
        if (root->left) st.push({root->left, s + to_string(root->left->val)});
        if (root->right)
          st.push({root->right, s + to_string(root->right->val)});
      }
    }
    return res;
  }
};
