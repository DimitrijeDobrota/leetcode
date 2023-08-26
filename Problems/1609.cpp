class Solution {
  public:
    bool isEvenOddTree(TreeNode *root) {
        if (!root) return false;

        queue<TreeNode *> q;
        TreeNode *de = new TreeNode(0);
        TreeNode *dd = new TreeNode(INT_MAX);

        q.push(root);
        for (int lvl = 0; !q.empty(); lvl++) {
            TreeNode *p = (lvl % 2 == 0) ? de : dd;
            for (int t = q.size(); t > 0; t--) {
                TreeNode *root = q.front();
                q.pop();
                if (lvl % 2 == 0) {
                    if (root->val % 2 != 1 || root->val <= p->val) return false;
                } else {
                    if (root->val % 2 != 0 || root->val >= p->val) return false;
                }
                p = root;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        return true;
    }
};
