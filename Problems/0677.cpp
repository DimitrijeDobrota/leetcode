// Only Trie
class MapSum {
    struct Node {
        Node(){};
        Node *children[27] = {nullptr};
        int &value = reinterpret_cast<int &>(children[0]);
        int trail = 0;
    };

    Node *trie = new Node();

  public:
    void insert(const string &key, int val) {
        Node *prev = trie;
        for (const char c : key) {
            const int idx = c & 0x1F;
            if (!prev->children[idx]) {
                prev = nullptr;
                break;
            };
            prev = prev->children[idx];
        }

        const int diff = prev ? val - prev->value : val;

        Node *crnt = trie;
        for (const char c : key) {
            const int idx = c & 0x1F;
            crnt->trail += diff;
            if (!crnt->children[idx]) crnt->children[idx] = new Node();
            crnt = crnt->children[idx];
        }
        crnt->value = val;
    }

    int sum(const string &prefix) const {
        const Node *crnt = trie;
        for (const char c : prefix) {
            const int idx = c & 0x1F;
            if (!crnt->children[idx]) return 0;
            crnt = crnt->children[idx];
        }
        return crnt->value + crnt->trail;
    }
};

// Trie + hash map
class MapSum {
    struct Node {
        Node(){};
        Node *children[27] = {nullptr};
        int &value = reinterpret_cast<int &>(children[0]);
    };

    Node *trie = new Node();
    unordered_map<string, int> um;

  public:
    void insert(const string &key, int val) {
        const int diff = val - um[key];

        Node *crnt = trie;
        for (const char c : key) {
            const int idx = c & 0x1F;
            crnt->value += diff;
            if (!crnt->children[idx]) crnt->children[idx] = new Node();
            crnt = crnt->children[idx];
        }
        crnt->value += diff;
        um[key] = val;
    }

    int sum(const string &prefix) const {
        const Node *crnt = trie;
        for (const char c : prefix) {
            const int idx = c & 0x1F;
            if (!crnt->children[idx]) return 0;
            crnt = crnt->children[idx];
        }
        return crnt->value;
    }
};
