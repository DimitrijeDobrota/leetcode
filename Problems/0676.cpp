class MagicDictionary {
    struct Node {
        Node(){};
        Node *children[27] = {nullptr};
        bool &terminate = reinterpret_cast<bool &>(children[0]);
    };

    Node *trie = new Node();

  public:
    void buildDict(const vector<string> &dictionary) {
        // create trie and fill it with words
        for (const auto &word : dictionary) {
            Node *crnt = trie;
            for (const char c : word) {
                const int idx = c & 0x1F;
                if (!crnt->children[idx]) crnt->children[idx] = new Node();
                crnt = crnt->children[idx];
            }
            crnt->terminate = true;
        }
    }

    bool search(const string &searchWord) {
        typedef pair<const Node *, int> entry;
        stack<entry> st;

        const int n = size(searchWord);

        // generate all posible char changes that make sense
        const Node *crnt = trie;
        for (int i = 0; i < n; i++) {
            const int idx = searchWord[i] & 0x1F;
            for (int j = 1; j <= 26; j++) {
                if (j == idx) continue;
                if (crnt->children[j]) st.emplace(crnt->children[j], i + 1);
            }
            if (!crnt->children[idx]) break;
            crnt = crnt->children[idx];
        }

        // check are any of them valid
        while (!st.empty()) {
            auto [crnt, start] = st.top();
            st.pop();
            for (int i = start; i < n; i++) {
                const int idx = searchWord[i] & 0x1F;
                if (!crnt->children[idx]) goto next;
                crnt = crnt->children[idx];
            }
            if (crnt->terminate) return true;
        next:;
        }
        return false;
    }
};
