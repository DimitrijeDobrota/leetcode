static const auto _ = []() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();

class Codec {
    typedef tuple<TreeNode **, int, int> record;

  public:
    // Encodes a tree to a single string.
    string serialize(const TreeNode *root) const {
        static int buff[10001];
        int idx = 0;

        if (!root) return "";

        stack<const TreeNode *> st;
        for (st.push(root); !st.empty();) {
            auto root = st.top();
            st.pop();
            while (root) {
                buff[idx++] = root->val;
                if (root->right) st.push(root->right);
                root = root->left;
            }
        }

        return string(reinterpret_cast<const char *>(buff), idx * 4);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(const string &sdata) const {
        auto data = reinterpret_cast<const int *>(sdata.data());
        TreeNode dummy, *node;
        stack<record> st;

        for (st.push({&dummy.left, 0, size(sdata) / 4}); !st.empty();) {
            auto [place, start, end] = st.top();
            st.pop();
            while (start != end) {
                node = *place = new TreeNode(data[start]);

                const auto mid = upper_bound(data + start, data + end, data[start]) - data;
                st.push({&node->right, mid, end});

                place = &node->left;
                start = start + 1;
                end = mid;
            }
        }

        return dummy.left;
    }
};
