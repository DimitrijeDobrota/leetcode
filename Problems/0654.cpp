class Solution {
  struct record {
    TreeNode **parent;
    int start, end;
    record(TreeNode **p, int s, int e) : parent(p), start(s), end(e) {}
  };

public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    TreeNode *head, tmp;
    stack<record> st;

    head = new TreeNode(-1);
    st.push({&head->right, 0, (int)nums.size()});
    while (!st.empty()) {
      auto [root, start, end] = st.top();
      st.pop();
      while (start < end) {
        int index = -1;
        for (int i = start, maxi = INT_MIN; i < end; i++)
          if (nums[i] > maxi) {
            maxi = nums[i];
            index = i;
          }
        *root = new TreeNode(nums[index]);
        st.push({&(*root)->left, start, index});
        root = &(*root)->right;
        start = index + 1;
      }
    }
    return head->right;
  }
};
