class Solution {
    TreeNode *duplicate(TreeNode *root) {
        TreeNode *dup = new TreeNode(root->val);
        if (root->left) dup->left = duplicate(root->left);
        if (root->right) dup->right = duplicate(root->right);
        return dup;
    }

    vector<TreeNode *> dp[20];

  public:
    vector<TreeNode *> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};
        if (1 == n) return {new TreeNode(0)};

        if (!dp[n].empty()) return dp[n];

        vector<TreeNode *> ret;
        for (int i = 2; i <= n; i += 2) {
            auto left = allPossibleFBT(i - 1);
            auto right = allPossibleFBT(n - i);
            for (int l = 0; l < left.size(); l++) {
                for (int r = 0; r < right.size(); r++) {
                    ret.push_back(new TreeNode(0));
                    ret.back()->left = (r == right.size() - 1) ? left[l] : duplicate(left[l]);
                    ret.back()->right = (l == left.size() - 1) ? right[r] : duplicate(right[r]);
                }
            }
        }

        return dp[n] = ret;
    }
};
