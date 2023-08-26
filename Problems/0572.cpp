class Solution {
    bool strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        vector<int> table(needle.size(), 0);

        for (int len = 0, j = 1; j < n;) {
            if (needle[j] == needle[len])
                table[j++] = ++len;
            else if (len)
                len = table[len - 1];
            else
                table[j++] = 0;
        }

        for (int i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) i++, j++;
            if (j == n) return true;
            if (i < m && haystack[i] != needle[j]) j ? j = table[j - 1] : i++;
        }

        return false;
    }

    string tree_preorder_string(TreeNode *root) {
        if (!root) return "";
        string res = "";
        stack<TreeNode *> st;

        st.push(root);
        while (!st.empty()) {
            TreeNode *root = st.top();
            st.pop();
            res += root ? "_" + to_string(root->val) : "#";
            if (!root) continue;
            st.push(root->right);
            st.push(root->left);
        }
        return res;
    }

  public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        string tree = tree_preorder_string(root);
        string sub = tree_preorder_string(subRoot);
        return strStr(tree, sub);
    }
};
