class Solution {
  public:
    vector<TreeNode *> delNodes(TreeNode *root, const vector<int> &to_delete) {
        const unordered_set<int> us(begin(to_delete), end(to_delete));
        vector<TreeNode *> res;

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode *crnt = q.front();
            q.pop();

            bool root = crnt->val > 0;
            crnt->val = abs(crnt->val);
            bool deleted = us.count(crnt->val);
            if (root && !deleted) res.push_back(crnt);

            if (crnt->left) {
                int val = crnt->left->val;
                if (!deleted) crnt->left->val = -val;
                q.push(crnt->left);
                if (us.count(val)) crnt->left = nullptr;
            }

            if (crnt->right) {
                int val = crnt->right->val;
                if (!deleted) crnt->right->val = -val;
                q.push(crnt->right);
                if (us.count(val)) crnt->right = nullptr;
            }
        }

        return res;
    }
};
