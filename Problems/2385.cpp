class Solution {
  public:
    int amountOfTime(TreeNode *root, int start) const {
        unordered_map<TreeNode *, TreeNode *> parent;
        queue<TreeNode *> q;
        TreeNode *infected;

        q.push(root);
        while (!q.empty()) {
            TreeNode *root = q.front();
            q.pop();
            if (root->val == start) {
                infected = root;
                break;
            }

            if (root->left) {
                parent.insert({root->left, root});
                q.push(root->left);
            }

            if (root->right) {
                parent.insert({root->right, root});
                q.push(root->right);
            }
        }

        int depth = -1;
        q = queue<TreeNode *>();
        q.push(infected);
        while (!q.empty()) {
            depth++;
            for (int k = q.size(); k > 0; k--) {
                TreeNode *root = q.front();
                q.pop();
                if (parent.count(root)) {
                    TreeNode *prnt = parent[root];
                    (prnt->left == root ? prnt->left : prnt->right) = nullptr;
                    q.push(parent[root]);
                }
                if (root->left) {
                    q.push(root->left);
                    parent.erase(root->left);
                }
                if (root->right) {
                    q.push(root->right);
                    parent.erase(root->right);
                }
            }
        }
        return depth;
    }
};
