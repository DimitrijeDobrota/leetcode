class Solution {
public:
  vector<double> averageOfLevels(TreeNode *root) {
    if (!root) return {};

    vector<double> res;
    queue<TreeNode *> q;

    q.push(root);
    for (int lvl = 0; !q.empty(); lvl++) {
      int cnt = 0;
      double sum = 0;
      for (int t = q.size(); t > 0; t--) {
        TreeNode *root = q.front();
        q.pop();
        sum += root->val;
        cnt++;
        if (root->left) q.push(root->left);
        if (root->right) q.push(root->right);
      }
      res.push_back(sum / cnt);
    }
    return res;
  }
}:
