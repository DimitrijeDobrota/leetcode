class Solution {
  void insert_after(Node **t, Node *n) {
    n->prev = *t;
    n->child = nullptr;
    (*t) = (*t)->next = n;
  }

public:
  Node *flatten(Node *head) {
    if (!head) return nullptr;

    stack<Node *> s;
    s.push(head);

    Node *h, *t;
    t = h = new Node();
    while (!s.empty()) {
      Node *self = s.top();
      s.pop();
      if (self->next) s.push(self->next);
      Node *child = self->child;
      insert_after(&t, self);
      while (child) {
        self = child;
        child = self->child;
        insert_after(&t, self);
        if (self->next) s.push(self->next);
      }
    }
    t->next = nullptr;
    h->next->prev = nullptr;
    return h->next;
  }
};
