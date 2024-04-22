class Solution {
    mutable int left, right, val;

    int count(const TreeNode *node) const {
        if (!node) return 0;
        int l = count(node->left), r = count(node->right);
        if (node->val == val) left = l, right = r;
        return l + r + 1;
    }

  public:
    bool btreeGameWinningMove(const TreeNode *root, int n, int x) const {
        val = x, n = count(root);
        return max(max(left, right), n - left - right - 1) > n / 2;
    }
};
