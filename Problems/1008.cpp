class Solution {
public:
  TreeNode *bstFromPreorder(vector<int> &preorder) {
    int index = 0;
    TreeNode *root = new TreeNode(preorder[index++]);
    stack<TreeNode *> st;
    st.push(root);
    while (index < preorder.size()) {
      int val = preorder[index++];
      if (val < st.top()->val) {
        st.push(st.top()->left = new TreeNode(val));
      } else {
        TreeNode *crnt = nullptr;
        while (!st.empty() && val > st.top()->val) crnt = st.top(), st.pop();
        st.push(crnt->right = new TreeNode(val));
      }
    }
    return root;
  }
};
