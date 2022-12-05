class Solution {
public:
  int countNodes(TreeNode *root) {
    if (!root) return 0;

    int height = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode *root = q.front();
      q.pop();
      int rh = 0, lh = 0;
      for (TreeNode *t = root; t; t = t->left) lh++;
      for (TreeNode *t = root; t; t = t->right) rh++;
      if (lh == rh)
        height += exp2(rh) - 1;
      else {
        height++;
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
      }
    }
    return height;
  }
};
