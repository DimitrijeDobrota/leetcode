// Not using BST property at all
class Solution {
  void travel(TreeNode *root, multiset<int> &s) {
    stack<TreeNode *> st;
    while (true) {
      while (root) {
        if (root->right) st.push(root->right);
        s.insert(root->val);
        root = root->left;
      }
      if (st.empty()) break;
      root = st.top(), st.pop();
    }
  }

public:
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> res;
    multiset<int> s;
    travel(root1, s), travel(root2, s);
    for (int n : s) res.push_back(n);
    return res;
  }
};

// Using BST property to travel both trees in-order
class Solution {
  void advance(TreeNode *root, stack<TreeNode *> &st) {
    while (root) {
      st.push(root);
      root = root->left;
    }
  }

  void append(vector<int> &res, stack<TreeNode *> &st) {
    res.push_back(st.top()->val);
    TreeNode *tmp = st.top();
    st.pop();
    advance(tmp->right, st);
  }

public:
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    stack<TreeNode *> st1, st2;
    vector<int> res;
    advance(root1, st1), advance(root2, st2);

    while (!st1.empty() && !st2.empty()) {
      if (st1.top()->val > st2.top()->val)
        append(res, st2);
      else
        append(res, st1);
    }
    if (st1.empty()) std::swap(st1, st2);
    while (!st1.empty()) append(res, st1);
    return res;
  }
};
