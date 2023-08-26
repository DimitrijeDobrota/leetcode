class Solution {
  public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) return {};

        vector<vector<int>> res;
        queue<TreeNode *> q;
        bool right = true;

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
            if (!right) reverse(res[lvl].begin(), res[lvl].end());
            right = !right;
        }
        return res;
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (!root) return {};

        vector<vector<int>> res;
        deque<TreeNode *> d;
        bool right = true;

        d.push_front(root);
        for (int lvl = 0; !d.empty(); lvl++, right = !right) {
            res.push_back(vector<int>());
            for (int t = d.size(); t > 0; t--) {
                TreeNode *root;
                if (right) {
                    root = d.front();
                    d.pop_front();
                    if (root->left) d.push_back(root->left);
                    if (root->right) d.push_back(root->right);
                } else {
                    root = d.back();
                    d.pop_back();
                    if (root->right) d.push_front(root->right);
                    if (root->left) d.push_front(root->left);
                }
                res[lvl].push_back(root->val);
            }
        }
        return res;
    }
};
