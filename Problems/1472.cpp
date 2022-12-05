class BrowserHistory {
  struct Node {
    Node *next, *prev;
    string val;
    Node(string val = "#", Node *prev = nullptr, Node *next = nullptr)
        : val(val), prev(prev), next(next) {}
  };
  Node *head = nullptr, *tail = nullptr, *crnt = nullptr;

public:
  BrowserHistory(string homepage) { crnt = head = tail = new Node(homepage); }

  void visit(string url) {
    for (Node *t = tail->next; t;) {
      Node *tmp = t;
      t = t->next;
      delete tmp;
    }
    crnt = tail = tail->next = new Node(url, tail, nullptr);
  }

  string back(int steps) {
    while (steps-- && crnt->prev) tail = crnt = crnt->prev;
    return crnt->val;
  }

  string forward(int steps) {
    while (steps-- && crnt->next) tail = crnt = crnt->next;
    return crnt->val;
  }
};
