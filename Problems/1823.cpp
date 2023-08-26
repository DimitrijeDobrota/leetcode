class Solution {
    struct Node {
        Node *next;
        int val;
        Node(int val = -1, Node *next = nullptr) : val(val), next(next) {}
    };

  public:
    int findTheWinner(int n, int k) {
        Node *h, *t;
        t = h = new Node();
        for (int i = 1; i <= n; i++)
            t = t->next = new Node(i);
        t->next = h->next;
        delete h;

        while (t != t->next) {
            for (int c = k - 1; c; c--)
                t = t->next;
            h = t->next;
            t->next = t->next->next;
            delete h;
        }

        return t->val;
    }
};
