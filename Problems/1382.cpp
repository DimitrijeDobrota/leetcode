class Solution {
    struct record {
        TreeNode *root;
        int low, high;
        record(TreeNode *root, int low, int high) : root(root), low(low), high(high) {}
    };

  public:
    TreeNode *balanceBST(TreeNode *root) {
        vector<TreeNode *> nums;

        {
            stack<TreeNode *> st;
            while (true) {
                while (root) {
                    st.push(root);
                    root = root->left;
                }
                if (st.empty()) break;
                root = st.top(), st.pop();
                nums.push_back(root);
                root = root->right;
            }
        }

        stack<record> st;
        TreeNode *head = new TreeNode(INT_MIN), *t;
        st.push({head, 0, (int)nums.size() - 1});
        while (!st.empty()) {
            record r = st.top();
            st.pop();
            while (r.low <= r.high) {
                int mid = r.low + (r.high - r.low) / 2;
                nums[mid]->left = nums[mid]->right = nullptr;
                (nums[mid]->val >= r.root->val ? r.root->right : r.root->left) = t = nums[mid];
                st.push({r.root = t, mid + 1, r.high});
                r.high = mid - 1;
            }
        }
        return head->right;
    }
};
