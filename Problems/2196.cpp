class Solution {
  public:
    TreeNode *createBinaryTree(const vector<vector<int>> &descriptions) {
        vector<bool> child(100001, false);
        TreeNode *um[100001] = {0};

        for (const auto &desc : descriptions) {
            if (!um[desc[0]]) um[desc[0]] = new TreeNode(desc[0]);
            if (!um[desc[1]]) um[desc[1]] = new TreeNode(desc[1]);
            (desc[2] ? um[desc[0]]->left : um[desc[0]]->right) = um[desc[1]];
            child[desc[1]] = true;
        }

        for (const auto &desc : descriptions) {
            if (!child[desc[0]]) return um[desc[0]];
        }

        return nullptr;
    }
};
