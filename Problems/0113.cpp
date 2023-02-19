class Solution {
public:
  vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (!root) return {};
    stack<pair<TreeNode *, int>> st;
    vector<vector<int>> res;
    vector<int> path;
    st.push({root, 0});
    while (!st.empty()) {
      auto [root, sum] = st.top();
      if (sum == INT_MIN) {
        st.pop();
        path.pop_back();
        continue;
      }
      sum += root->val;
      st.top().second = INT_MIN;
      path.push_back(root->val);

      if (!root->left && !root->right && sum == targetSum) res.push_back(path);
      if (root->left) st.push({root->left, sum});
      if (root->right) st.push({root->right, sum});
    }
    return res;
  }
};
