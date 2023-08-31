class Solution {
  public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        int8_t height[1001] = {0};
        stack<TreeNode *> s({root});

        TreeNode *res;
        int maxi = INT_MIN;
        while (!s.empty()) {
            TreeNode *root = s.top();
            if (root->val >= 0) {
                if (root->left) {
                    height[root->left->val] = height[root->val] + 1;
                    s.push(root->left);
                }
                if (root->right) {
                    height[root->right->val] = height[root->val] + 1;
                    s.push(root->right);
                }
                root->val = -root->val - 1;
                continue;
            }
            s.pop();
            root->val = -(root->val + 1);

            if (!root->left && !root->right) {
                if (height[root->val] > maxi) {
                    maxi = height[root->val];
                    res = root;
                }
                continue;
            }

            int8_t l = 0, r = 0;
            if (root->left) l = height[root->left->val];
            if (root->right) r = height[root->right->val];

            if (l || r) height[root->val] = max(l, r);
            if (height[root->val] >= maxi && l == r) {
                maxi = height[root->val];
                res = root;
            }
        }
        return res;
    }
};
