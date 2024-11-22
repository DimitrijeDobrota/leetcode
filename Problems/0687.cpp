class Solution {
    int res = 0;

    int rec(const TreeNode *root, int parent) {
        if (!root) return 0;

        const auto l = rec(root->left, root->val), r = rec(root->right, root->val);

        res = max(res, l + r);
        return root->val == parent ? max(l, r) + 1 : 0;
    }

  public:
    int longestUnivaluePath(const TreeNode *root) {
        rec(root, -1);
        return res;
    }
};
