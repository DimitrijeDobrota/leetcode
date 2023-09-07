class Solution {
  public:
    bool flipEquiv(const TreeNode *root1, const TreeNode *root2) const {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;

        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right));
    }
};
