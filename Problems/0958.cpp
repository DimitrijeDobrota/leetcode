class Solution {
public:
  bool isCompleteTree(TreeNode *root) {
    queue<TreeNode *> q;
    int had_empty = 0;
    q.push(root);
    while (!q.empty()) {
      TreeNode *root = q.front();
      q.pop();
      if (!root) {
        had_empty = 1;
        continue;
      }
      if (had_empty) return false;
      q.push(root->left);
      q.push(root->right);
    }
    return true;
  }
};
