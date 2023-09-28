class Solution {
    int distance(const vector<int> &a, const vector<int> &b) const {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }

  public:
    bool escapeGhosts(const vector<vector<int>> &ghosts, const vector<int> &target) const {
        const int pm = distance(target, {0, 0});
        for (const auto &ghost : ghosts)
            if (pm >= distance(target, ghost)) return false;
        return true;
    }
};
