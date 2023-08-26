class MyHashSet {
    class Node {
      public:
        int val;
        Node *next;

        Node() : val(-1), next(nullptr) {}
        Node(int val, Node *next) : val(val), next(next) {}
    };

    static constexpr int SIZE = 10007;
    Node bucket[SIZE] = {};

    int hash(int key) { return key % SIZE; }

  public:
    MyHashSet() {}

    void add(int key) {
        if (contains(key)) return;
        Node *b = &bucket[hash(key)];
        b->next = new Node(key, b->next);
    }

    void remove(int key) {
        Node *prev = &bucket[hash(key)], *crnt = prev->next;
        while (crnt && crnt->val != key) {
            prev = crnt;
            crnt = crnt->next;
        }
        if (!crnt) return;
        prev->next = crnt->next;
        delete crnt;
    }

    bool contains(int key) {
        for (Node *crnt = bucket[hash(key)].next; crnt; crnt = crnt->next)
            if (crnt->val == key) return true;
        return false;
    }
};
