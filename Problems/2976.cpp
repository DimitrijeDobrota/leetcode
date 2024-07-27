class Solution {
  public:
    long long minimumCost(const string &source, const string &target, const vector<char> &original,
                          const vector<char> &changed, const vector<int> &cost) const {
        static unsigned long long path[26][26];
        memset(path, 0xFF, sizeof(path));

        for (int i = 0; i < size(cost); i++) {
            auto &cpath = path[original[i] - 'a'][changed[i] - 'a'];
            cpath = min(cpath, (unsigned long long)cost[i]);
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                if (path[i][k] == -1) continue;

                for (int j = 0; j < 26; j++) {
                    if (path[k][j] == -1) continue;

                    path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
                }
            }
        }

        long long res = 0;

        for (int i = 0; i < size(source); i++) {
            if (source[i] == target[i]) continue;

            const auto cost = path[source[i] - 'a'][target[i] - 'a'];
            if (cost == -1) return -1;

            res += cost;
        }

        return res;
    }
};
