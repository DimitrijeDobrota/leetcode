// Naive approach using vector to precompute in-order traversal

class BSTIterator {
  vector<int> vec;
  int current = 0;

public:
  BSTIterator(TreeNode *root) {
    stack<TreeNode *> st;
    while (true) {
      while (root) {
        st.push(root);
        root = root->left;
      }
      if (st.empty()) break;
      root = st.top();
      st.pop();
      vec.push_back(root->val);
      root = root->right;
    }
  }

  int next() { return vec[current++]; }

  bool hasNext() { return current < vec.size(); }
};

// Compute in-order on the fly

class BSTIterator {
  stack<TreeNode *> st;

  void fill_stack(TreeNode *root) {
    while (root) {
      st.push(root);
      root = root->left;
    }
  }

public:
  BSTIterator(TreeNode *root) { fill_stack(root); }

  int next() {
    int val = st.top()->val;
    TreeNode *root = st.top()->right;
    st.pop();
    fill_stack(root);
    return val;
  }

  bool hasNext() { return !st.empty(); }
};
