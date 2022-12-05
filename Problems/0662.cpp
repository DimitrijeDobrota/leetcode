class Solution {
public:
  int widthOfBinaryTree(TreeNode *root) {
    int maxi = 0;
    queue<TreeNode *> q;
    q.push(root);
    for (int lvl = 0; !q.empty(); lvl++) {
      int first = -1, last = -1;
      for (int t = q.size(); t > 0; t--) {
        TreeNode *root = q.front();
        q.pop();
        if (root) {
          if (first == -1) first = t;
          last = t;
        }
        if (!root) continue;

        q.push(root->left);
        q.push(root->right);
      }
      maxi = max(maxi, first - last);
    }
    return maxi;
  }
};
