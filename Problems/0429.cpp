class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
        if (!root) return {};

        vector<vector<int>> res;
        queue<Node *> q;

        q.push(root);
        for (int lvl = 0; !q.empty(); lvl++) {
            res.push_back(vector<int>());
            for (int t = q.size(); t > 0; t--) {
                Node *root = q.front();
                q.pop();
                res[lvl].push_back(root->val);
                for (Node *c : root->children)
                    q.push(c);
            }
        }
        return res;
    }
};
