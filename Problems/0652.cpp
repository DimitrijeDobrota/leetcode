class Solution {
  public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
        if (!root) return {};

        unordered_map<string, vector<TreeNode *>> seen;
        unordered_map<TreeNode *, string> um;
        vector<TreeNode *> res;
        stack<TreeNode *> st;

        st.push(root);
        um[nullptr] = "#";
        while (!st.empty()) {
            auto root = st.top();

            if (um.count(root)) {
                um[root] = to_string(root->val) + ' ' + um[root->left] + ' ' + um[root->right];
                seen[um[root]].push_back(root);
                st.pop();
                continue;
            }

            um[root] = "";
            if (root->right) st.push(root->right);
            if (root->left) st.push(root->left);
        }

        for (const auto &[k, v] : seen)
            if (v.size() > 1) res.push_back(v.back());

        return res;
    }
};
