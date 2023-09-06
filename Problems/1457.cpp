
class Solution {
    int count[10] = {0};

  public:
    int pseudoPalindromicPaths(TreeNode *root) {
        int res = 0;

        count[root->val]++;
        if (!root->left && !root->right) {
            int odd = 0;
            for (int i = 1; i <= 9; i++)
                if (count[i] % 2 && odd++) break;
            res = odd <= 1;
        } else {
            if (root->left) res += pseudoPalindromicPaths(root->left);
            if (root->right) res += pseudoPalindromicPaths(root->right);
        }
        count[root->val]--;

        return res;
    }
};
