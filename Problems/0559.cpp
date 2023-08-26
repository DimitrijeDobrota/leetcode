class Solution {
  public:
    int maxDepth(Node *root) {
        if (!root) return 0;

        int lvl;
        queue<Node *> q;
        q.push(root);
        for (lvl = 0; !q.empty(); lvl++) {
            for (int t = q.size(); t > 0; t--) {
                Node *root = q.front();
                q.pop();
                for (Node *c : root->children)
                    q.push(c);
            }
        }
        return lvl;
    }
};
