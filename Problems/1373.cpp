class Solution {
  struct record {
    int sum, mini, maxi;
    record(int su = 0, int mi = INT_MAX, int ma = INT_MIN)
        : sum(su), mini(mi), maxi(ma) {}
  };

public:
  int maxSumBST(TreeNode *root) {
    unordered_map<TreeNode *, record> um;
    stack<TreeNode *> st;

    int res = 0;
    st.push(root);
    while (!st.empty()) {
      TreeNode *root = st.top();
      st.pop();
      if (um.count(root)) {
        record &r = um[root];
        if (root->left) {
          if (root->val <= um[root->left].maxi) {
            r.mini = INT_MIN, r.maxi = INT_MAX;
            continue;
          } else
            r.sum += um[root->left].sum;
        }

        if (root->right) {
          if (root->val >= um[root->right].mini) {
            r.mini = INT_MIN, r.maxi = INT_MAX;
            continue;
          } else
            r.sum += um[root->right].sum;
        }

        res = max(res, r.sum);
        r.mini = root->left ? um[root->left].mini : root->val;
        r.maxi = root->right ? um[root->right].maxi : root->val;
        continue;
      }
      um.insert({root, root->val});
      st.push(root);
      if (root->left) st.push(root->left);
      if (root->right) st.push(root->right);
    }
    return res;
  }
};
