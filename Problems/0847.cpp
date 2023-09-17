class Solution {
    bool seen[12][1 << 12] = { 0 };

public:
    int shortestPathLength(const vector<vector<int>>& graph) {
        const int n = graph.size(), goal = (1 << n) - 1;

        queue<tuple<int,int,int>> q;
        for(int i = 0; i < n; i++) {
            q.push({i, 1 << i, 0});
            seen[i][1 << i] = true;
        }

        while (!q.empty()) {
            const auto [idx, mask, dist] = q.front(); q.pop();

            if(mask == goal) return dist;
            for(const auto v: graph[idx]) {
                const int mask_v = mask | 1 << v;
                if(!seen[v][mask_v]) {
                    q.push({v, mask_v, dist+1});
                    seen[v][mask_v] = true;
                }
            }
        }

        return 0;
    }
};
