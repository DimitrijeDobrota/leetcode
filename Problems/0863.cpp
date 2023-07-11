class Solution {
  TreeNode *parent[501];
  void find(TreeNode *root, TreeNode *target) {
    queue<TreeNode *> q({root});

    parent[root->val] = NULL;
    while (!q.empty()) {
      for (int k = q.size(); k > 0; k--) {
        TreeNode *root = q.front();
        q.pop();
        if (root == target) return;
        if (root->left) {
          parent[root->left->val] = root;
          q.push(root->left);
        }
        if (root->right) {
          parent[root->right->val] = root;
          q.push(root->right);
        }
      }
    }
  }

public:
  vector<int> distanceK(TreeNode *root, TreeNode *target, int k) {
    if (k == 0) return {target->val};
    find(root, target);

    vector<int> res;
    while (k-- >= 0) {
      queue<TreeNode *> q({target});
      for (int i = 0; i <= k && !q.empty(); i++) {
        for (int t = q.size(); t > 0; t--) {
          TreeNode *root = q.front();
          q.pop();
          if (root->left) q.push(root->left);
          if (root->right) q.push(root->right);
        }
      }
      while (!q.empty()) {
        res.push_back(q.front()->val);
        q.pop();
      }

      TreeNode *p = parent[target->val];
      if (!p) break;
      (p->left == target ? p->left : p->right) = NULL;
      target = p;
    }
    return res;
  }
};
