class Solution {
public:
  string tree2str(TreeNode *root) {
    if (!root) return "";

    string res = "";
    stack<TreeNode *> st;
    unordered_set<TreeNode *> us;

    st.push(root);
    while (!st.empty()) {
      TreeNode *root = st.top();
      if (us.find(root) != us.end()) {
        res += ")";
        st.pop();
      } else {
        us.insert(root);
        res += "(" + to_string(root->val);
        if (!root->left && !root->right) continue;
        if (root->right) st.push(root->right);
        if (root->left)
          st.push(root->left);
        else
          res += "()";
      }
    }
    return res.substr(1, res.size() - 2);
  }
};
