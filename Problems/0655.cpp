class Solution {
    int height(const TreeNode *root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    typedef tuple<TreeNode *, int, int> record;

  public:
    vector<vector<string>> printTree(TreeNode *root) {
        const int n = height(root), m = (1 << n) - 1;
        vector<vector<string>> res(n, vector<string>(m));

        queue<record> q;
        q.push({root, 0, (m - 1) / 2});
        while (!q.empty()) {
            const auto [root, r, c] = q.front();
            q.pop();
            res[r][c] = to_string(root->val);
            if (root->left) q.push({root->left, r + 1, c - (1 << (n - r - 2))});
            if (root->right) q.push({root->right, r + 1, c + (1 << (n - r - 2))});
        }
        return res;
    }
};
