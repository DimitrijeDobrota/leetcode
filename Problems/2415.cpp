class Solution {
  public:
    TreeNode *reverseOddLevels(TreeNode *root) {
        static vector<TreeNode *> vec(8192);
        queue<TreeNode *> q({root});
        for (int lvl = 0; !q.empty(); lvl++) {
            for (int k = q.size() - 1; k >= 0; k--) {
                vec[k] = q.front();
                q.pop();
                if (vec[k]->left) q.push(vec[k]->left);
                if (vec[k]->right) q.push(vec[k]->right);
            }
            if (lvl % 2 == 0) continue;
            int i = 0, j = (1 << lvl) - 1;
            while (i < j)
                swap(vec[i++]->val, vec[j--]->val);
        }
        return root;
    }
};
