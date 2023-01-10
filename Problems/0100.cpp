// Recursive solution
class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    return p->val == q->val && isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
  }
};

// Iterative solution
class Solution {
public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    queue<pair<TreeNode *, TreeNode *>> qu;
    qu.push({p, q});
    while (!qu.empty()) {
      auto [p, q] = qu.front();
      qu.pop();
      if (p->val != q->val) return false;

      if (p->left && q->left)
        qu.push({p->left, q->left});
      else if (p->left || q->left)
        return false;

      if (p->right && q->right)
        qu.push({p->right, q->right});
      else if (p->right || q->right)
        return false;
    }

    return true;
  }
};
