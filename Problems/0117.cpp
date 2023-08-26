class Solution {
  public:
    Node *connect(Node *root) {
        if (!root) return {};

        queue<Node *> q;
        q.push(root);
        for (int lvl = 0; !q.empty(); lvl++) {
            Node *prev = nullptr;
            for (int t = q.size(); t > 0; t--) {
                Node *root = q.front();
                q.pop();
                root->next = prev;
                prev = root;
                if (root->right) q.push(root->right);
                if (root->left) q.push(root->left);
            }
        }
        return root;
    }
};
