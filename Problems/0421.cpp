class Solution {
    struct Node {
        Node *child[2] = {nullptr, nullptr};
    };

    Node trie;

    void insert(const int n) {
        Node *crnt = &trie;
        bitset<32> bs = n;

        for (int i = 31; i >= 0; i--) {
            const auto c = bs[i];
            if (!crnt->child[c]) crnt->child[c] = new Node();
            crnt = crnt->child[c];
        }
    }

    int find(const int n) const {
        const Node *crnt = &trie;
        bitset<32> bs = n;

        int res = 0;
        for (int i = 31; i >= 0; i--) {
            const auto c = bs[i];
            if (crnt->child[!c]) {
                crnt = crnt->child[!c];
                res += 1 << i;
            } else {
                crnt = crnt->child[c];
            }
        }
        return res;
    }

  public:
    int findMaximumXOR(const vector<int> &nums) {
        for (const int n : nums)
            insert(n);

        int res = 0;
        for (const int n : nums)
            res = max(res, find(n));
        return res;
    }
};
