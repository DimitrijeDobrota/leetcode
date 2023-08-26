class Solution {
    int res = 0;

    int dfs(TreeNode *root, bool zig) {
        if (!root) return -1;

        int left = dfs(root->left, false);
        int right = dfs(root->right, true);
        res = max(res, max(left + 1, right + 1));

        return zig ? left + 1 : right + 1;
    }

  public:
    int longestZigZag(TreeNode *root) {
        dfs(root, false);
        return res;
    }
};
