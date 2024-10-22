class Solution {
  public:
    long long kthLargestLevelSum(const TreeNode *root, int k) const {
        priority_queue<long long, vector<long long>, greater<>> pq;
        queue<const TreeNode *> q;

        for (q.emplace(root); !q.empty();) {
            long long sum = 0;
            for (int k = size(q); k > 0; k--) {
                const auto root = q.front();
                q.pop();
                sum += root->val;

                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }

            pq.emplace(sum);
            if (size(pq) > k) pq.pop();
        }

        return size(pq) == k ? pq.top() : -1;
    }
};
