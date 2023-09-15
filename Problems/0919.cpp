class CBTInserter {
    TreeNode *root = nullptr;
    queue<TreeNode *> q;

  public:
    CBTInserter(TreeNode *root) : root(root), q({root}) {}
    TreeNode *get_root() { return root; }

    int insert(int val) {
        TreeNode *node = new TreeNode(val);
        while (!q.empty()) {
            TreeNode *root = q.front();
            if (root->left)
                q.push(root->left);
            else {
                root->left = node;
                q.push(root->left);
                return root->val;
            }

            q.pop();

            if (root->right)
                q.push(root->right);
            else {
                root->right = node;
                q.push(root->right);
                return root->val;
            }
        }

        return -1;
    }
};
