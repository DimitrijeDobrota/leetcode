class Solution {
  public:
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> q({root});

        int res = -1;
        while (!q.empty()) {
            TreeNode *root = q.front();
            q.pop();
            res = root->val;
            if (root->right) q.push(root->right);
            if (root->left) q.push(root->left);
        }

        return res;
    }
};
