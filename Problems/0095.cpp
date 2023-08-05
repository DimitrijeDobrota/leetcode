class Solution {
  vector<TreeNode *> dp[10][10];

  vector<TreeNode *> rec(int n, int left, int right) {
    vector<TreeNode *> &res = dp[left][right];
    if (!res.empty()) return res;

    for (int i = left; i <= right; i++) {
      for (const auto &l : rec(n, left, i - 1)) {
        for (const auto &r : rec(n, i + 1, right)) {
          res.push_back(new TreeNode(i, l, r));
        }
      }
    }
    if (res.empty()) return {nullptr};
    return res;
  }

public:
  vector<TreeNode *> generateTrees(int n) { return rec(n, 1, n); }
};
