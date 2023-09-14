class Solution {
    vector<string> res;
    int n;

    typedef unordered_map<string, map<string, int>> adj_t;
    bool rec(adj_t &adj) {
        if (res.size() == n) return true;

        const string &name = res.back();
        for (auto &next : adj[name]) {
            if (!next.second) continue;
            res.push_back(next.first);
            next.second--;
            if (rec(adj)) return true;
            next.second++;
            res.pop_back();
        }
        return false;
    }

  public:
    vector<string> findItinerary(const vector<vector<string>> &tickets) {
        adj_t adj;

        n = tickets.size() + 1;
        for (const auto &ticket : tickets)
            adj[ticket[0]][ticket[1]]++;

        res = {"JFK"};
        rec(adj);
        return res;
    }
};
