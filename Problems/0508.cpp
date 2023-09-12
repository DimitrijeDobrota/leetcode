class Solution {
  public:
    vector<int> findFrequentTreeSum(TreeNode *root) {
        unordered_map<int, int> um;
        stack<TreeNode *> st({root});
        while (!st.empty()) {
            TreeNode *root = st.top();
            if (root) {
                st.push(nullptr);
                if (root->left) st.push(root->left);
                if (root->right) st.push(root->right);
                continue;
            }
            st.pop();
            root = st.top();
            st.pop();
            if (root->left) root->val += root->left->val;
            if (root->right) root->val += root->right->val;
            um[root->val]++;
        }

        vector<int> res;
        int maxi = 0;
        for (const auto [k, v] : um) {
            if (v < maxi) continue;
            if (v == maxi)
                res.push_back(k);
            else {
                maxi = v;
                res = {k};
            }
        }
        return res;
    }
};
