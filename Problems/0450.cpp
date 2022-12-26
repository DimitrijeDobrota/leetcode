class Solution {
  TreeNode *deleteRoot(TreeNode *root) {
    if (!root) return nullptr;
    if (!root->left) return root->right;
    if (!root->right) return root->left;

    TreeNode *next = root->right;
    TreeNode *pre = nullptr;
    while (next->left) {
      pre = next;
      next = next->left;
    }
    next->left = root->left;
    if (root->right != next) {
      pre->left = next->right;
      next->right = root->right;
    }
    return next;
  }

public:
  TreeNode *deleteNode(TreeNode *root, int key) {
    TreeNode *cur = root, *pre = nullptr;
    while (cur && cur->val != key) {
      pre = cur;
      cur = key < cur->val ? cur->left : cur->right;
    }

    if (!pre) return deleteRoot(cur);
    (pre->left == cur ? pre->left : pre->right) = deleteRoot(cur);
    return root;
  }
};
