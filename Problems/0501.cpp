class Solution {
  public:
    vector<int> findMode(TreeNode *root) {
        stack<TreeNode *> st;

        int maxi = INT_MIN, cnt = 0, prev = -1;
        vector<int> res;
        while (true) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            if (st.empty()) break;
            root = st.top(), st.pop();
            if (root->val != prev) {
                if (cnt >= maxi) {
                    if (cnt > maxi) res.clear();
                    maxi = cnt;
                    res.push_back(prev);
                }
                prev = root->val;
                cnt = 1;
            } else
                cnt++;
            root = root->right;
        }
        if (cnt >= maxi) {
            if (cnt > maxi) res.clear();
            maxi = cnt;
            res.push_back(prev);
        }
        return res;
    }
};
