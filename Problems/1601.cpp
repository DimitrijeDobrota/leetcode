class Solution {
    int degree[21] = {0};
    int res = 0;

    void rec(const vector<vector<int>> &req, int cur = 0, int cnt = 0, int dirty = 0) {
        if (cnt + (req.size() - cur) < res) return;
        if (cur == req.size()) {
            if (dirty) return;
            res = max(res, cnt);
            return;
        }

        rec(req, cur + 1, cnt, dirty);

        if (degree[req[cur][0]]++ == 0) dirty++;
        if (--degree[req[cur][1]] == 0) dirty--;
        rec(req, cur + 1, cnt + 1, dirty);
        degree[req[cur][0]]--, degree[req[cur][1]]++;
    }

  public:
    int maximumRequests(int n, const vector<vector<int>> &requests) {
        rec(requests);
        return res;
    }
};
