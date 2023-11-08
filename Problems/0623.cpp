class Solution {
  public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth) const {
        if (depth == 1) return new TreeNode(val, root, nullptr);
        queue<TreeNode *> q;
        q.push(root);
        for (int lvl = 2; !q.empty(); lvl++) {
            for (int k = q.size(); k > 0; k--) {
                TreeNode *root = q.front();
                q.pop();
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
                if (lvl == depth) {
                    root->left = new TreeNode(val, root->left, nullptr);
                    root->right = new TreeNode(val, nullptr, root->right);
                }
            }
        }
        return root;
    }
};
