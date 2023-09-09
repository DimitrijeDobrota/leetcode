class Solution {
  public:
    int countCompleteComponents(int n, const vector<vector<int>> &edges) {
        static uint64_t con[50];

        for (uint64_t i = 0; i < n; i++)
            con[i] = 1ll << i;
        for (const auto &edge : edges) {
            con[edge[0]] |= 1ll << edge[1];
            con[edge[1]] |= 1ll << edge[0];
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!con[i]) continue;
            for (uint64_t crnt = con[i] ^ (1ll << i), idx; crnt; crnt ^= 1ll << idx) {
                idx = __builtin_ctzll(crnt);
                if (con[idx] != con[i]) goto next;
                con[idx] = 0;
            }
            res++;
        next:;
        }

        return res;
    }
};
