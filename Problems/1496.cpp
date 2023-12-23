struct Hash {
    size_t operator()(const tuple<int, int> &t) const { return (get<0>(t) << 16) + get<1>(t); }
};

class Solution {
  public:
    bool isPathCrossing(const string &path) const {
        static const pair<int, int> moves[128] = {
            ['N'] = {-1, 0}, ['S'] = {1, 0}, ['E'] = {0, 1}, ['W'] = {0, -1}};
        unordered_set<tuple<int, int>, Hash> us;
        int x = 0, y = 0;
        us.insert({0, 0});
        for (const char c : path) {
            x += moves[c].first;
            y += moves[c].second;
            if (us.count({x, y})) return true;
            us.insert({x, y});
        }
        return false;
    }
};
