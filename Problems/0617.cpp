class Solution {
public:
  TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2) {
    if (!root1 && !root2) return nullptr;
    if (!root2)
      return new TreeNode(root1->val, mergeTrees(root1->left, nullptr),
                          mergeTrees(root1->right, nullptr));
    if (!root1)
      return new TreeNode(root2->val, mergeTrees(nullptr, root2->left),
                          mergeTrees(nullptr, root2->right));
    return new TreeNode(root1->val + root2->val,
                        mergeTrees(root1->left, root2->left),
                        mergeTrees(root1->right, root2->right));
  }
};
