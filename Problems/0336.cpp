static bool isPalindrome(const string &s, int i, int j) {
    while (i < j) {
        if (s[i++] != s[j--]) return false;
    }

    return true;
}

class Trie {
    struct Node {
        Node *children[26] = {0};
        vector<int> suffix;
        int idx = -1;
    } root;

  public:
    void insert(const string &s, int idx) {
        Node *crnt = &root;

        for (int i = size(s) - 1; i >= 0; i--) {
            auto &child = crnt->children[s[i] - 'a'];
            if (!child) child = new Node();
            if (isPalindrome(s, 0, i)) crnt->suffix.push_back(idx);

            crnt = child;
        }

        crnt->suffix.push_back(idx);
        crnt->idx = idx;
    }

    void query(const string &s, int idx, vector<vector<int>> &res) const {
        const Node *crnt = &root;
        const int n = size(s);

        for (int i = 0; i < n; i++) {
            if (crnt->idx != -1 && crnt->idx != idx && isPalindrome(s, i, n - 1)) {
                res.push_back({idx, crnt->idx});
            }

            crnt = crnt->children[s[i] - 'a'];
            if (!crnt) return;
        }

        for (const auto n : crnt->suffix) {
            if (n == idx) continue;
            res.push_back({idx, n});
        }
    }
};

class Solution {
  public:
    vector<vector<int>> palindromePairs(const vector<string> &words) const {
        const int n = size(words);
        vector<vector<int>> res;
        Trie trie;

        for (int i = 0; i < n; i++)
            trie.insert(words[i], i);
        for (int i = 0; i < n; i++)
            trie.query(words[i], i, res);

        return res;
    }
};
