class Solution {
  public:
    int minimumOperations(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            vector<int> lvl, idx(q.size());
            for (int k = q.size(); k > 0; k--) {
                TreeNode *root = q.front();
                q.pop();
                lvl.push_back(root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            iota(begin(idx), end(idx), 0);
            sort(begin(idx), end(idx), [&](const int i, const int j) { return lvl[i] < lvl[j]; });
            for (int i = 0; i < idx.size(); i++) {
                for (; idx[i] != i; res++)
                    swap(idx[i], idx[idx[i]]);
            }
        }
        return res;
    }
};
