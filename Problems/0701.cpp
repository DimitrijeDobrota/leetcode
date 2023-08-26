class Solution {
  public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        if (!root) return new TreeNode(val);

        TreeNode *prev = nullptr;
        for (TreeNode *tmp = root; tmp;) {
            prev = tmp;
            tmp = val < tmp->val ? tmp->left : tmp->right;
        }

        (val > prev->val ? prev->right : prev->left) = new TreeNode(val);
        return root;
    }
};
