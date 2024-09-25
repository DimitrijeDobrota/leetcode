class Solution {
    class Trie {
        struct Node {
            Node *children[26] = {nullptr};
            int count = 0;
        } node;

      public:
        void insert(const string &word) {
            Node *crnt = &node;

            for (const char c : word) {
                const auto idx = c - 'a';
                if (!crnt->children[idx]) crnt->children[idx] = new Node();
                crnt = crnt->children[idx];
                crnt->count++;
            }
        }

        int count(const string &word) const {
            const Node *crnt = &node;
            int res = 0;

            for (const char c : word) {
                const auto idx = c - 'a';
                crnt = crnt->children[idx];
                res += crnt->count;
            }

            return res;
        }
    };

  public:
    vector<int> sumPrefixScores(const vector<string> &words) const {
        vector<int> res;
        Trie trie;

        for (const auto &word : words)
            trie.insert(word);
        for (const auto &word : words)
            res.push_back(trie.count(word));

        return res;
    }
};
