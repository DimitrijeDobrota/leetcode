class Trie {
    struct Node {
        Node(){};
        Node *children[27] = {nullptr};
        bool &terminate = reinterpret_cast<bool &>(children[0]);
    };

    Node *trie = new Node();

    int length_rec(const Node *node, int len = 0) const {
        int res = 1, had = 0;
        for (int i = 1; i <= 26; i++) {
            if (!node->children[i]) continue;
            if (had) res += len + 1;
            res += length_rec(node->children[i], len + 1);
            had = true;
        }
        return res;
    }

  public:
    void insert(const string &s) {
        Node *crnt = trie;
        for (int i = s.size() - 1; i >= 0; i--) {
            const int idx = s[i] & 0x1F;
            if (!crnt->children[idx]) crnt->children[idx] = new Node();
            crnt = crnt->children[idx];
        }
        crnt->terminate = true;
    }

    int length(void) const { return length_rec(trie); }
};

class Solution {
  public:
    int minimumLengthEncoding(const vector<string> &words) {
        Trie trie;
        for (const string &word : words)
            trie.insert(word);
        return trie.length();
    }
};
