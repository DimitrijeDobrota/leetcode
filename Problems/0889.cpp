class Solution {
  public:
    TreeNode *constructFromPrePost(const vector<int> &pre, const vector<int> &post) {
        vector<TreeNode *> s = {new TreeNode(pre[0])};
        for (int i = 1, j = 0; i < pre.size(); i++) {
            TreeNode *node = new TreeNode(pre[i]);
            while (s.back()->val == post[j])
                s.pop_back(), j++;
            (!s.back()->left ? s.back()->left : s.back()->right) = node;
            s.push_back(node);
        }
        return s.front();
    }
};
