class Solution {
  public:
    string smallestFromLeaf(const TreeNode *root) const {
        queue<pair<const TreeNode *, string>> q;
        q.emplace(root, "");

        string res(16, 'z');
        while (!q.empty()) {
            for (int k = q.size(); k > 0; k--) {
                auto [root, s] = q.front();
                q.pop();
                s += 'a' + root->val;

                if (root->left) q.emplace(root->left, s);
                if (root->right) q.emplace(root->right, s);

                if (!root->left && !root->right) {
                    reverse(begin(s), end(s));
                    res = min(res, s);
                }
            }
        }

        return res;
    }
};
