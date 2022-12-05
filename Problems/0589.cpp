class Solution {
public:
  vector<int> preorder(Node *root) {
    if (!root) return {};
    vector<int> res;
    stack<Node *> st;
    st.push(root);
    while (!st.empty()) {
      Node *root = st.top();
      st.pop();
      res.push_back(root->val);
      reverse(root->children.begin(), root->children.end());
      for (Node *c : root->children) st.push(c);
    }
    return res;
  }
};
