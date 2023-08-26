class Solution {
    struct record {
        TreeNode *root;
        ListNode *low, *high;
        record(TreeNode *root, ListNode *low = nullptr, ListNode *high = nullptr)
            : root(root), low(low), high(high) {}
    };
    ListNode *get_mid(ListNode *list, ListNode *end) {
        ListNode *slow, *fast;
        slow = fast = list;
        while (fast != end && fast->next != end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

  public:
    TreeNode *sortedListToBST(ListNode *head) {
        stack<record> st;
        TreeNode *tree = new TreeNode(INT_MIN), *t;
        st.push({tree, head, nullptr});
        while (!st.empty()) {
            record r = st.top();
            st.pop();
            while (r.low != r.high) {
                ListNode *mid = get_mid(r.low, r.high);
                (mid->val >= r.root->val ? r.root->right : r.root->left) = t = new TreeNode(mid->val);
                st.push({r.root = t, mid->next, r.high});
                r.high = mid;
            }
        }
        return tree->right;
    }
};
