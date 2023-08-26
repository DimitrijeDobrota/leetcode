class Solution {
    typedef vector<int>::iterator vii;
    struct Record {
        TreeNode **fill = nullptr;
        vii start, end;
        Record(TreeNode **f, vii s, vii e) : fill(f), start(s), end(e) {}
    };

  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        stack<Record> st;
        TreeNode head;
        int pre = 0;

        st.push({&head.right, inorder.begin(), inorder.end()});
        while (!st.empty()) {
            Record r = st.top();
            st.pop();
            while (r.start < r.end) {
                vii mid = find(r.start, r.end, preorder[pre]);
                if (mid == r.end) break;
                TreeNode *n = *r.fill = new TreeNode(preorder[pre++]);
                st.push({&n->right, next(mid), r.end});
                r.end = mid;
                r.fill = &n->left;
            }
        }

        return head.right;
    }
};
