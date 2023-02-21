class Codec {
public:
  string serialize(TreeNode *root) {
    ostringstream out;
    serialize(root, out);
    return out.str();
  }

  TreeNode *deserialize(string data) {
    istringstream in(data);
    return deserialize(in);
  }

private:
  void serialize(TreeNode *root, ostringstream &out) {
    stack<TreeNode *> st;

    st.push(root);
    while (!st.empty()) {
      TreeNode *root = st.top();
      st.pop();
      if (!root)
        out << "# ";
      else {
        out << root->val << ' ';
        st.push(root->right);
        st.push(root->left);
      }
    }
  }

  TreeNode *deserialize(istringstream &in) {
    string val;
    in >> val;
    if (val == "#") return nullptr;
    TreeNode *root = new TreeNode(stoi(val));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
  }
};
