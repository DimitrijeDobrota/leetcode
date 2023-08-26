class FindElements {
    TreeNode *root;
    unordered_set<int> all;

  public:
    FindElements(TreeNode *root) : root(root) {
        queue<TreeNode *> q({root});
        root->val = 0;
        while (!q.empty()) {
            TreeNode *root = q.front();
            q.pop();
            all.insert(root->val);
            if (root->left) {
                root->left->val = 2 * root->val + 1;
                q.push(root->left);
            }
            if (root->right) {
                root->right->val = 2 * root->val + 2;
                q.push(root->right);
            }
        }
    }

    bool find(int target) { return all.count(target); }
};
