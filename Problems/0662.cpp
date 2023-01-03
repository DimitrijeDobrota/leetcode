class Solution {
public:
  int widthOfBinaryTree(TreeNode *root) {
    if (root == NULL) return 0;
    queue<pair<TreeNode *, int>> q;

    int res = 1;
    q.push({root, 0});
    while (!q.empty()) {
      int start = q.front().second, end = q.back().second;

      res = max(res, end - start + 1);
      for (int k = q.size(); k > 0; k--) {
        pair<TreeNode *, int> p = q.front();
        q.pop();
        int idx = p.second - start;

        if (p.first->left) q.push({p.first->left, 2ll * idx + 1});
        if (p.first->right) q.push({p.first->right, 2ll * idx + 2});
      }
    }

    return res;
  }
};
