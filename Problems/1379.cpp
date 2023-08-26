class Solution {
  public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target) {
        if (!original || !cloned || !target) return nullptr;

        stack<pair<TreeNode *, TreeNode *>> st;

        st.push({original, cloned});
        while (!st.empty()) {
            TreeNode *original = st.top().first;
            TreeNode *cloned = st.top().second;
            st.pop();

            if (original == target) return cloned;

            if (original->left) st.push({original->left, cloned->left});
            if (original->right) st.push({original->right, cloned->right});
        }

        return nullptr;
    }
};
