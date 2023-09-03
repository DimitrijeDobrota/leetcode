class Solution {
  public:
    vector<int> restoreArray(const vector<vector<int>> &adjacentPairs) {
        const int n = adjacentPairs.size() + 1;
        unordered_map<int, vector<int>> um;

        for (const auto &p : adjacentPairs) {
            um[p[0]].push_back(p[1]);
            um[p[1]].push_back(p[0]);
        }

        int start = -1;
        for (const auto &[k, v] : um) {
            if (v.size() == 1) {
                start = k;
                break;
            }
        }

        vector<int> res(n);
        res[0] = start, res[1] = um[start][0];
        for (int i = 2; i < n; i++) {
            res[i] = um[res[i - 1]][0] != res[i - 2] ? um[res[i - 1]][0] : um[res[i - 1]][1];
        }
        return res;
    }
};
