class Solution {
  public:
    int deepestLeavesSum(TreeNode *root) {
        int sum = 0;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            sum = 0;
            for (int k = q.size(); k > 0; k--) {
                TreeNode *root = q.front();
                q.pop();
                sum += root->val;
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        return sum;
    }
};
