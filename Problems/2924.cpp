class Solution {
  public:
    int findChampion(int n, const vector<vector<int>> &edges) const {
        bitset<128> bs;
        for (const auto &edge : edges)
            bs.set(edge[1]);
        if (bs.count() + 1 != n) return -1;
        for (int i = 0; i < n; i++)
            if (!bs.test(i)) return i;
        return -2;
    }
};
