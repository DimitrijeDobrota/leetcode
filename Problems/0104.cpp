class Solution {
public:
  int maxDepth(TreeNode *root) {
    if (!root) return 0;

    int lvl;
    queue<TreeNode *> q;
    q.push(root);
    for (lvl = 0; !q.empty(); lvl++) {
      for (int t = q.size(); t > 0; t--) {
        TreeNode *root = q.front();
        q.pop();
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
      }
    }
    return lvl;
  }
};
