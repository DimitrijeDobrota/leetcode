class Solution {
public:
  int minDepth(TreeNode *root) {
    if (!root) return 0;

    queue<TreeNode *> q;

    q.push(root);
    for (int lvl = 1; !q.empty(); lvl++) {
      for (int t = q.size(); t > 0; t--) {
        TreeNode *root = q.front();
        q.pop();
        if (!root->left && !root->right) return lvl;
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
      }
    }
    return -1;
  }
};
