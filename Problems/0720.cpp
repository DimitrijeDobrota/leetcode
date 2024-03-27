class Solution {
    struct Node {
        Node *children[26] = {0};
        bool term = false;

        void insert(const string &s) {
            Node *crnt = this;
            for (int i = 0; i < size(s); i++) {
                const int idx = s[i] - 'a';
                if (!crnt->children[idx]) crnt->children[idx] = new Node();
                crnt = crnt->children[idx];
            }
            crnt->term = true;
        }

        bool check(const string &s) const {
            const Node *crnt = this;
            for (int i = 0; i < size(s); i++) {
                const int idx = s[i] - 'a';
                if (!crnt->children[idx]) return false;
                crnt = crnt->children[idx];
                if (!crnt->term) return false;
            }
            return true;
        }
    };

  public:
    string longestWord(const vector<string> &words) const {
        Node trie;
        string res;

        for (const auto &word : words)
            trie.insert(word);
        for (const auto &word : words) {
            if (!trie.check(word)) continue;
            if (size(word) > size(res))
                res = word;
            else if (size(word) == size(res))
                res = min(res, word);
        }

        return res;
    }
};
