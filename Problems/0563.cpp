class Solution {
    int res = 0;

    int sum_adding_tilt(TreeNode *root) {
        if (!root) return 0;
        int l = sum_adding_tilt(root->left);
        int r = sum_adding_tilt(root->right);
        res += abs(l - r);
        return l + r + root->val;
    }

  public:
    int findTilt(TreeNode *root) {
        res = 0;
        sum_adding_tilt(root);
        return res;
    }
};
