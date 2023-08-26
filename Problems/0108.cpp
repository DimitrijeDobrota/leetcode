class Solution {
    struct record {
        TreeNode *root;
        int low, high;
        record(TreeNode *root, int low, int high) : root(root), low(low), high(high) {}
    };

  public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        stack<record> st;
        TreeNode *head = new TreeNode(INT_MIN), *t;
        st.push({head, 0, (int)nums.size() - 1});
        while (!st.empty()) {
            record r = st.top();
            st.pop();
            while (r.low <= r.high) {
                int mid = r.low + (r.high - r.low) / 2;
                (nums[mid] >= r.root->val ? r.root->right : r.root->left) = t = new TreeNode(nums[mid]);
                st.push({r.root = t, mid + 1, r.high});
                r.high = mid - 1;
            }
        }
        return head->right;
    }
};
