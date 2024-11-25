class Solution {
    using type_t = pair<uint32_t, uint32_t>;

    static type_t encode(const vector<vector<int>> &board) {
        uint32_t n2p = 0; // number to position
        uint32_t p2n = 0; // position to number

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                const int idx = i * 3 + j;
                n2p |= idx << (board[i][j] * 3);
                p2n |= board[i][j] << (idx * 3);
            }
        }

        return {n2p, p2n};
    }

  public:
    int slidingPuzzle(const vector<vector<int>> &board) const {
        static const vector<vector<int>> adj = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};

        unordered_set<uint32_t> seen;
        queue<type_t> q;

        q.push(encode(board));
        for (int lvl = 0; !q.empty(); lvl++) {
            for (int k = size(q); k > 0; k--) {
                const auto [n2p, p2n] = q.front();
                q.pop();

                if (n2p == 0x23445) return lvl;

                const auto p = n2p & 0x7;                    // position of zero
                for (const auto sp : adj[p]) {               // position to swap
                    const auto sn = (p2n >> (sp * 3)) & 0x7; // number to swap

                    const auto sn2p = (n2p & ~((0x7 << (sn * 3)) | (0x7 << (0 * 0)))) | (p << (sn * 3)) | sp;
                    const auto sp2n = (p2n & ~((0x7 << (sp * 3)) | (0x7 << (p * 3)))) | (sn << (p * 3));

                    if (!seen.count(sn2p)) {
                        q.emplace(sn2p, sp2n);
                        seen.insert(sn2p);
                    }
                }
            }
        }

        return -1;
    }
};
