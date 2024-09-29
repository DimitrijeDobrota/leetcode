class AllOne {
    struct Node {
        int freq = 0;
        Node *prev = nullptr;
        Node *next = nullptr;
        unordered_set<string> keys;
    };

    unordered_map<string, Node *> map;
    Node head = {0, nullptr, &tail};
    Node tail = {0, &head, nullptr};

  public:
    void inc(const string &key) {
        if (map.find(key) != map.end()) {
            Node *node = map[key];
            int freq = node->freq;
            node->keys.erase(key);

            Node *nnode = node->next;
            if (nnode == &tail || nnode->freq != freq + 1) {
                map[key] = node->next = nnode->prev = new Node(freq + 1, node, nnode, {key});
            } else {
                nnode->keys.insert(key);
                map[key] = nnode;
            }

            if (node->keys.empty()) {
                removeNode(node);
            }
        } else {
            Node *firstNode = head.next;
            if (firstNode == &tail || firstNode->freq > 1) {
                map[key] = head.next = firstNode->prev = new Node(1, &head, firstNode, {key});
            } else {
                firstNode->keys.insert(key);
                map[key] = firstNode;
            }
        }
    }

    void dec(const string &key) {
        if (map.find(key) == map.end()) {
            return;
        }

        Node *node = map[key];
        node->keys.erase(key);

        int freq = node->freq;
        if (freq == 1) {
            map.erase(key);
        } else {
            Node *pnode = node->prev;
            if (pnode == &head || pnode->freq != freq - 1) {
                map[key] = pnode->next = node->prev = new Node(freq - 1, pnode, node, {key});
            } else {
                pnode->keys.insert(key);
                map[key] = pnode;
            }
        }

        if (node->keys.empty()) {
            removeNode(node);
        }
    }

    string getMaxKey() const { return tail.prev == &head ? "" : *(tail.prev->keys.begin()); }

    string getMinKey() const { return head.next == &tail ? "" : *(head.next->keys.begin()); }

  private:
    void removeNode(Node *node) {
        Node *pnode = node->prev;
        Node *nnode = node->next;

        pnode->next = nnode;
        nnode->prev = pnode;

        delete node;
    }
};
