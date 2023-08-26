class Solution {
  public:
    int sumNumbers(TreeNode *root) {
        if (!root) return 0;

        int sum = 0, res = 0;
        stack<pair<TreeNode *, int>> st;
        while (true) {
            while (root) {
                sum *= 10;
                sum += root->val;
                if (root->right)
                    st.push({root->right, sum});
                else if (!root->left)
                    res += sum;
                root = root->left;
            }
            if (st.empty()) break;
            root = st.top().first;
            sum = st.top().second;
            st.pop();
        }

        return res;
    }
};
