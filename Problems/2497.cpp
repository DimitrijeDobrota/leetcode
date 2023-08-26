class Solution {
  public:
    int maxStarSum(vector<int> &vals, vector<vector<int>> &edges, int k) {
        vector<vector<int>> adj(vals.size());

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int res = INT_MIN;
        for (int i = 0; i < vals.size(); i++) {
            priority_queue<int, vector<int>, greater<int>> pq;
            for (int c : adj[i]) {
                if (vals[c] <= 0) continue;
                pq.push(vals[c]);
                if (pq.size() > k) pq.pop();
            }
            int sum = vals[i];
            while (!pq.empty())
                sum += pq.top(), pq.pop();
            res = max(res, sum);
        }
        return res;
    }
};
