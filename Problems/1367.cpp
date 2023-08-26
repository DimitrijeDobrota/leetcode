class Solution {
    vector<int> needle, lps;

    void computeKMPTable(vector<int> needle) {
        lps.resize(needle.size(), 0);

        for (int len = 0, j = 1; j < size(needle);) {
            if (needle[j] == needle[len])
                lps[j++] = ++len;
            else if (len)
                len = lps[len - 1];
            else
                lps[j++] = 0;
        }
    }

    bool kmpSearch(TreeNode *root, int j) {
        if (j == size(needle)) return true;
        if (!root) return false;
        while (j > 0 && root->val != needle[j])
            j = lps[j - 1];
        if (root->val == needle[j]) j++;
        return kmpSearch(root->left, j) || kmpSearch(root->right, j);
    }

  public:
    bool isSubPath(ListNode *head, TreeNode *root) {
        if (!head || !root) return false;

        needle.resize(0);
        for (ListNode *t = head; t; t = t->next)
            needle.push_back(t->val);

        computeKMPTable(needle);
        return kmpSearch(root, 0);
    }
};
