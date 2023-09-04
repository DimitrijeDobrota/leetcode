class Solution {
  public:
    TreeNode *replaceValueInTree(TreeNode *root) {
        queue<TreeNode *> q({root});
        vector<TreeNode *> buf;
        root->val = 0;
        while (!q.empty()) {
            int sum = 0;
            buf.clear();
            for (int k = q.size(); k > 0; k--) {
                TreeNode *node = q.front();
                q.pop();
                buf.push_back(node);

                if (node->left) {
                    sum += node->left->val;
                    q.push(node->left);
                }

                if (node->right) {
                    sum += node->right->val;
                    q.push(node->right);
                }
            }
            for (auto node : buf) {
                int t = sum;
                if (node->left) t -= node->left->val;
                if (node->right) t -= node->right->val;
                if (node->left) node->left->val = t;
                if (node->right) node->right->val = t;
            }
        }
        return root;
    }
};
