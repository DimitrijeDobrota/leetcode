// Recursive
class Solution {
  public:
    int countPairs(TreeNode *root, int distance) {
        unordered_map<TreeNode *, vector<int>> um;
        stack<TreeNode *> st;
        int res = 0;

        st.push(root);
        while (!st.empty()) {
            TreeNode *root = st.top();
            if (root) {
                st.push(nullptr);
                if (!root->left && !root->right)
                    um[root].push_back(1);
                else {
                    if (root->left) st.push(root->left);
                    if (root->right) st.push(root->right);
                }
                continue;
            }
            st.pop();
            root = st.top();
            st.pop();

            for (const int n : um[root->right])
                um[root].push_back(n + 1);

            for (const int a : um[root->left]) {
                um[root].push_back(a + 1);
                for (const int b : um[root->right])
                    if (a + b <= distance) res++;
            }
        }
        return res;
    }
};

// Iterative
class Solution {
    int res = 0;
    vector<int> rec(TreeNode *root, int distance) {
        if (!root->left && !root->right) return {1};
        vector<int> left, right, sum;
        if (root->left) left = rec(root->left, distance);
        if (root->right) right = rec(root->right, distance);

        sum.reserve(left.size() + right.size());
        for (const int b : right)
            sum.push_back(b + 1);
        for (const int a : left) {
            sum.push_back(a + 1);
            for (const int b : right) {
                res += (a + b <= distance);
            }
        }
        return sum;
    }

  public:
    int countPairs(TreeNode *root, int distance) {
        rec(root, distance);
        return res;
    }
};
