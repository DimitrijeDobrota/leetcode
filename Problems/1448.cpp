class Solution {
public:
  int goodNodes(TreeNode *root) {
    queue<pair<TreeNode *, int>> q({
        {root, INT_MIN}
    });
    int res = 0;

    while (!q.empty()) {
      const auto [root, maxi] = q.front();
      q.pop();
      if (root->val >= maxi) res++;
      if (root->left) q.push({root->left, max(maxi, root->val)});
      if (root->right) q.push({root->right, max(maxi, root->val)});

      // For some reason it increases runtime and decreases memory usage
      // Must be leetcode error...
      root->left = root->right = nullptr;
    }
    return res;
  }
};
