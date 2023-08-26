class Solution {
  public:
    vector<int> rightSideView(TreeNode *root) {
        if (!root) return {};

        vector<int> res;
        queue<TreeNode *> q;
        q.push(root);
        for (int lvl = 0; !q.empty(); lvl++) {
            res.push_back(q.front()->val);
            for (int k = q.size(); k > 0; k--) {
                TreeNode *root = q.front();
                q.pop();
                if (root->right) q.push(root->right);
                if (root->left) q.push(root->left);
            }
        }
        return res;
    }
};
