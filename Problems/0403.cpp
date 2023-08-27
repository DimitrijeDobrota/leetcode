class Solution {
    bool dp[2001][2001] = {false};
    unordered_map<int, int> um;

    bool rec(const vector<int> &stones, int idx = 0, int k = 0) {
        if (idx == stones.size() - 1) return true;
        if (dp[k][idx]) return false;
        dp[k][idx] = true;

        for (int jmp = k + 1; jmp >= k - 1 && jmp > 0; jmp--) {
            if (um.count(stones[idx] + jmp)) {
                if (rec(stones, um[stones[idx] + jmp], jmp)) return true;
            }
        }

        return false;
    }

  public:
    bool canCross(const vector<int> &stones) {
        for (int i = 0; i < stones.size(); i++)
            um.insert({stones[i], i});
        return rec(stones);
    }
};
