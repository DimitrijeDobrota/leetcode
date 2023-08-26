class Solution {
  public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> &paths) {
        vector<vector<int>> adj(n);
        for (auto &p : paths) {
            adj[p[0] - 1].push_back(p[1] - 1);
            adj[p[1] - 1].push_back(p[0] - 1);
        }

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            bitset<5> colors;

            for (int c : adj[i])
                colors.set(res[c]);

            for (int j = 1; j < 5; j++) {
                if (colors[j]) continue;
                res[i] = j;
                break;
            }
        }
        return res;
    }
};
