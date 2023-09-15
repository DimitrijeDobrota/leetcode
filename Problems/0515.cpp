class Solution {
  public:
    vector<int> largestValues(const TreeNode *root) {
        if (!root) return {};

        vector<int> res;
        queue<const TreeNode *> q({root});
        while (!q.empty()) {
            int maxi = INT_MIN;
            for (int k = q.size(); k > 0; k--) {
                const TreeNode *root = q.front();
                q.pop();
                maxi = max(maxi, root->val);
                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            res.push_back(maxi);
        }
        return res;
    }
};
