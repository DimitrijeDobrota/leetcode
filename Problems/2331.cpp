class Solution {
public:
  bool evaluateTree(TreeNode *root) {
    switch (root->val) {
    case 0:
    case 1: return root->val;
    case 2: return evaluateTree(root->left) || evaluateTree(root->right);
    case 3: return evaluateTree(root->left) && evaluateTree(root->right);
    default: return false;
    }
  }
};
