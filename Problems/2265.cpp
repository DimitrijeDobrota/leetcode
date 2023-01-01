class Solution {
public:
  int averageOfSubtree(TreeNode *root) {
    stack<TreeNode *> st;
    unordered_map<TreeNode *, int> um;
    int res = 0;

    st.push(root);
    while (!st.empty()) {
      TreeNode *root = st.top();
      if (root == nullptr) {
        st.pop(), root = st.top(), st.pop();
        int sum = root->val, count = 1;
        if (root->left) {
          sum += root->left->val;
          count += um[root->left];
        }
        if (root->right) {
          sum += root->right->val;
          count += um[root->right];
        }
        if (root->val == sum / count) res++;
        um[root] = count;
        root->val = sum;
        continue;
      }
      st.push(nullptr);
      if (root->left) st.push(root->left);
      if (root->right) st.push(root->right);
    }
    return res;
  }
};
