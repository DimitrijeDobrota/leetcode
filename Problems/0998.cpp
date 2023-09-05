class Solution {
  public:
    TreeNode *insertIntoMaxTree(TreeNode *root, int val) {
        TreeNode *node = new TreeNode(val), *cur = root;
        if (root->val < val) {
            node->left = root;
            return node;
        }

        while (cur->right && cur->right->val > val)
            cur = cur->right;

        node->left = cur->right;
        cur->right = node;
        return root;
    }
};
