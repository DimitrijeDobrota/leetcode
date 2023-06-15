class Solution {
public:
  int maxLevelSum(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);

    int maxi = INT_MIN, index = -1;
    for (int lvl = 1; !q.empty(); lvl++) {
      int sum = 0;
      for (int k = q.size(); k > 0; k--) {
        TreeNode *root = q.front();
        q.pop();
        sum += root->val;
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
      }
      if (sum > maxi) {
        maxi = sum;
        index = lvl;
      }
    }
    return index;
  }
};
