class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) return {};

        vector<vector<int>> res;
        queue<TreeNode *> q;

        q.push(root);
        for (int lvl = 0; !q.empty(); lvl++) {
            res.push_back(vector<int>());
            for (int t = q.size(); t > 0; t--) {
                TreeNode *root = q.front();
                q.pop();
                res[lvl].push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
        }
        return res;
    }
};
