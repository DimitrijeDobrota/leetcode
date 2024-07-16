class Solution {
    bool find(TreeNode *n, int val, string &path) const {
        if (n->val == val) return true;

        if (n->left && find(n->left, val, path))
            path.push_back('L');
        else if (n->right && find(n->right, val, path))
            path.push_back('R');

        return !path.empty();
    }

  public:
    string getDirections(TreeNode *root, int startValue, int destValue) const {
        string s, d;

        find(root, startValue, s);
        find(root, destValue, d);

        while (!s.empty() && !d.empty() && s.back() == d.back())
            s.pop_back(), d.pop_back();
        return string(s.size(), 'U') + string(rbegin(d), rend(d));
    }
};
