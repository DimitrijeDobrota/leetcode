class Solution {
public:
  Node *cloneGraph(Node *node) {
    if (!node) return nullptr;

    Node *head = new Node(node->val);
    unordered_map<Node *, Node *> um({
        {node, head}
    });

    stack<Node *> st;
    st.push(node);
    while (!st.empty()) {
      Node *node = st.top();
      st.pop();
      for (Node *c : node->neighbors) {
        if (um.find(c) != um.end()) {
          um[node]->neighbors.push_back(um[c]);
          continue;
        }
        Node *n = new Node(c->val);
        um[node]->neighbors.push_back(n);
        um.insert(make_pair(c, n));
        st.push(c);
      }
    }
    return head;
  }
};
