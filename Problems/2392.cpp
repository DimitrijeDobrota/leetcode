class Solution {
    static vector<int> create(int k, const vector<vector<int>> &conditions) {
        vector<vector<int>> adj(k + 1);
        static int count[402];

        memset(count, 0x00, sizeof(count));
        for (const auto &row : conditions) {
            adj[row[0]].push_back(row[1]);
            count[row[1]]++;
        }

        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (count[i] != 0) continue;
            q.push(i);
        }

        if (q.empty()) return {};

        int cnt = 0;
        vector<int> res(k + 1, -1);
        while (!q.empty()) {
            const auto crnt = q.front();
            q.pop();

            for (const int below : adj[crnt]) {
                if (--count[below] != 0) continue;
                q.push(below);
            }

            res[crnt] = cnt++;
        }

        return cnt == k ? res : vector<int>();
    }

  public:
    vector<vector<int>> buildMatrix(int k, const vector<vector<int>> &rowConditions,
                                    const vector<vector<int>> &colConditions) const {
        const auto row = create(k, rowConditions);
        if (row.empty()) return {};

        const auto col = create(k, colConditions);
        if (col.empty()) return {};

        vector<vector<int>> res(k, vector(k, 0));
        for (int i = 1; i <= k; i++)
            res[row[i]][col[i]] = i;

        return res;
    }
};
