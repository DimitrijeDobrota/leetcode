class Solution {
  public:
    TreeNode *sufficientSubset(TreeNode *root, int limit) const {
        stack<pair<TreeNode *, int>> st;
        unordered_set<TreeNode *> deleted;

        st.emplace(root, root->val);
        while (!st.empty()) {
            if (st.top().first) {
                auto [root, sum] = st.top();
                st.emplace(nullptr, 0);
                if (root->left) st.emplace(root->left, sum + root->left->val);
                if (root->right) st.emplace(root->right, sum + root->right->val);
                continue;
            }

            st.pop();
            auto [root, sum] = st.top();
            st.pop();

            if (!root->left && !root->right) {
                if (sum < limit) deleted.insert(root);
            } else {
                int children = 0, del = 0;
                if (root->left) {
                    children++;
                    if (deleted.count(root->left)) {
                        root->left = nullptr;
                        del++;
                    }
                }
                if (root->right) {
                    children++;
                    if (deleted.count(root->right)) {
                        root->right = nullptr;
                        del++;
                    }
                }
                if (children == del) deleted.insert(root);
            }
        }

        return !deleted.count(root) ? root : nullptr;
    }
};
