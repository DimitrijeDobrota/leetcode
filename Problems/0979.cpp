class Solution {
  public:
    int distributeCoins(TreeNode *root) {
        TreeNode dummy(0);
        stack<pair<TreeNode *, TreeNode *>> q({{root, &dummy}});

        int res = 0;
        while (!q.empty()) {
            auto [root, parent] = q.top();
            if (root) {
                q.push({nullptr, nullptr});
                if (root->left) q.push({root->left, root});
                if (root->right) q.push({root->right, root});
                continue;
            }
            q.pop();
            tie(root, parent) = q.top();
            q.pop();
            parent->val += root->val - 1;
            res += abs(root->val - 1);
        }

        return res;
    }
};
