class Solution {
  public:
    Node *copyRandomList(Node *head) {
        if (!head) return nullptr;

        unordered_map<Node *, Node *> um;
        Node *h, *t;
        t = h = new Node(-1);
        for (Node *p = head; p; p = p->next) {
            t = t->next = new Node(p->val);
            um.insert(make_pair(p, t));
        }

        t = h->next;
        for (Node *p = head; p; p = p->next, t = t->next) {
            if (p->random != nullptr) t->random = um[p->random];
        }
        return h->next;
    }
};
