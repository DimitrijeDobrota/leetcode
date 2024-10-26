class Solution {
  public:
    vector<int> treeQueries(const TreeNode *root, vector<int> &queries) const {
        static int height[100002];
        memset(height, 0x00, sizeof(height));

        stack<const TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            if (st.top() != nullptr) {
                const auto *root = st.top();
                st.push(nullptr);
                if (root->left) st.push(root->left);
                if (root->right) st.push(root->right);
                continue;
            }

            st.pop();
            const auto *root = st.top();
            st.pop();

            int &h = height[root->val];
            if (root->left) h = max(h, height[root->left->val] + 1);
            if (root->right) h = max(h, height[root->right->val] + 1);
        }

        queue<const TreeNode *> q;
        q.push(root);
        for (int lvl = 0; !q.empty(); lvl++) {
            int f = 100001, s = 100001;

            queue<const TreeNode *> copy = q;
            for (int k = size(q); k > 0; k--) {
                const auto *root = q.front();
                q.pop();
                const int val = root->val;

                if (height[val] > height[f])
                    s = f, f = val;
                else if (height[val] > height[s])
                    s = val;

                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }

            if (size(copy) == 1) {
                height[copy.front()->val] = lvl - 1;
                continue;
            }

            const int hf = height[f], hs = height[s];
            while (!copy.empty()) {
                const int n = copy.front()->val;
                copy.pop();
                if (n != f)
                    height[n] = hf + lvl;
                else
                    height[n] = hs + lvl;
            }
        }

        for (auto &n : queries)
            n = height[n];
        return queries;
    }
};
