class Solution {
  public:
    int rob(TreeNode *root) const {
        if (!root) return 0;
        if (root->val < 0) return -root->val;

        int res = root->val;
        if (root->left) res += rob(root->left->left) + rob(root->left->right);
        if (root->right) res += rob(root->right->left) + rob(root->right->right);

        root->val = -max(res, rob(root->left) + rob(root->right));
        return -root->val;
    }
};
