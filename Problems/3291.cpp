class Trie {
    struct Node {
        Node *children[26] = {0};
    } root;

  public:
    void insert(const string &s) {
        Node *crnt = &root;

        for (const char c : s) {
            const int idx = c - 'a';
            if (!crnt->children[idx]) crnt->children[idx] = new Node();
            crnt = crnt->children[idx];
        }
    }

    int find(const string &s, int start) const {
        const Node *crnt = &root;
        int n = 0;

        for (int i = start; i < size(s); i++, n++) {
            const int idx = s[i] - 'a';
            if (!crnt->children[idx]) break;
            crnt = crnt->children[idx];
        }

        return n;
    }
};

class Solution {
  public:
    int minValidStrings(const vector<string> &words, const string &target) const {
        static unsigned dp[5001];
        const int n = size(target);
        Trie trie;

        for (const auto &word : words)
            trie.insert(word);

        memset(dp, 0xFF, sizeof(dp));
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == -1) continue;
            const int limit = trie.find(target, i);
            for (int len = 1; len <= limit; len++) {
                dp[i + len] = min(dp[i + len], dp[i] + 1);
            }
        }

        return dp[n];
    }
};
