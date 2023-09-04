class Solution {
  public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> comb;
        for (uint16_t i = 0; i < (1 << 9); i++) {
            if (__builtin_popcount(i) != k) continue;
            int crnt = i, total = 0;

            comb.clear();
            while (crnt) {
                comb.push_back(__builtin_ffs(crnt));
                total += comb.back();
                crnt &= crnt - 1;
            }
            if (total == n) res.push_back(comb);
        }
        return res;
    }
};
