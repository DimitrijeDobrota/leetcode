// Brute force
class Solution {
  public:
    int pathSum(TreeNode *root, int targetSum) {
        if (!root) return 0;

        stack<TreeNode *> st;
        queue<TreeNode *> q;

        st.push(root);
        while (!st.empty()) {
            TreeNode *root = st.top();
            st.pop();
            q.push(root);
            if (root->left) st.push(root->left);
            if (root->right) st.push(root->right);
        }

        int res = 0;
        while (!q.empty()) {
            stack<pair<TreeNode *, long long>> st;
            st.push({q.front(), 0});
            q.pop();
            while (!st.empty()) {
                auto [root, sum] = st.top();
                st.pop();
                sum += root->val;
                if (sum == targetSum) res++;
                if (root->left) st.push({root->left, sum});
                if (root->right) st.push({root->right, sum});
            }
        }

        return res;
    }
};

// Optimized
class Solution {
  public:
    int pathSum(TreeNode *root, int targetSum) {
        if (!root) return 0;
        queue<pair<TreeNode *, vector<long long>>> q;
        int res = 0;

        q.push({root, {}});
        while (!q.empty()) {
            auto &[root, vec] = q.front();
            long long sum = root->val + (vec.size() ? vec.back() : 0);

            for (int num : vec)
                if (sum - num == targetSum) res++;
            if (sum == targetSum) res++;

            if (root->left) {
                q.push({root->left, vec});
                q.back().second.push_back(sum);
            }

            if (root->right) {
                q.push({root->right, vec});
                q.back().second.push_back(sum);
            }

            q.pop();
        }

        return res;
    }
};
