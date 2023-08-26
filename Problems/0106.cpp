class Solution {
    class Record {
      public:
        int low, high;
        TreeNode **field;
        Record(int l, int h, TreeNode **f) : low(l), high(h), field(f) {}
    };

  public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        unordered_map<int, int> um;
        for (int i = 0; i < inorder.size(); i++)
            um[inorder[i]] = i;

        int crnt = postorder.size() - 1;
        TreeNode head, *nw;
        stack<Record> st;

        st.push({0, (int)inorder.size(), &head.right});
        while (!st.empty()) {
            Record r = st.top();
            st.pop();
            while (r.low < r.high) {
                int pos = um[postorder[crnt]];
                nw = *r.field = new TreeNode(postorder[crnt--]);
                st.push({r.low, pos, &nw->left});
                r.low = pos + 1;
                r.field = &nw->right;
            }
        }
        return head.right;
    }
};
