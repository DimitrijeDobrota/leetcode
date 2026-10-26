#include "../Templates/Union_Find.cpp"

class Solution {
  public:
    int minimumHammingDistance(vector<int> &source, vector<int> &target, vector<vector<int>> &allowedSwaps) {
        int n = source.size();
        UnionFind uf(n);

        for (auto &s : allowedSwaps)
            uf.join(s[0], s[1]);

        vector<unordered_map<int, int>> vus(n);
        for (int i = 0; i < n; i++) {
            int pos = uf.find(i).index();
            vus[pos][target[i]]++;
            vus[pos][source[i]]--;
        }

        int res = 0;
        for (int i = 0; i < n; i++)
            for (auto [_, val] : vus[i])
                res += abs(val);

        return res / 2;
    }
};
