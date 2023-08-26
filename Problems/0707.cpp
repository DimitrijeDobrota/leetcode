class MyLinkedList {
    struct Node {
        int val;
        Node *next;

        Node(int val, Node *next = nullptr) : val(val), next(next) {}
    };

    Node *head = nullptr, *tail = nullptr;
    int size = 0;

  public:
    MyLinkedList() {}

    int get(int index) {
        if (index >= size) return -1;

        Node *p = head;
        while (index--)
            p = p->next;
        return p->val;
    }

    void addAtHead(int val) {
        if (!head)
            head = tail = new Node(val);
        else
            head = new Node(val, head);
        size++;
    }

    void addAtTail(int val) {
        if (!head)
            head = tail = new Node(val);
        else
            tail = tail->next = new Node(val);
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size) return;

        Node *p = head;
        size++;

        if (index == 0) {
            addAtHead(val);
            return;
        }

        while (--index)
            p = p->next;
        p->next = new Node(val, p->next);
        if (p == tail) tail = p->next;
    }

    void deleteAtIndex(int index) {
        if (index >= size) return;

        Node *t, *p;
        size--;

        if (index == 0) {
            cout << "head" << endl;
            t = head;
            head = head->next;
            delete t;
            return;
        }

        p = head;
        while (--index)
            p = p->next;

        t = p->next;
        p->next = p->next->next;
        if (t == tail) tail = p;
        delete t;
    }
};
