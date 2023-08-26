class Solution {
  public:
    bool isCousins(TreeNode *root, int x, int y) {
        if (!root) return {};

        bool fx = false, fy = false;
        queue<TreeNode *> q;
        q.push(root);
        for (int lvl = 0; !q.empty(); lvl++) {
            for (int t = q.size(); t > 0; t--) {
                TreeNode *root = q.front();
                q.pop();
                if (root->left && root->right)
                    if ((root->left->val == x && root->right->val == y) ||
                        (root->left->val == y && root->right->val == x))
                        return false;

                if (root->val == x) fx = true;
                if (root->val == y) fy = true;

                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }

            if (fx && fy) return true;

            if (fx || fy) return false;
        }
        return false;
    }
};
