class Solution {
  public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {
        sort(begin(people), end(people),
             [](const auto &a, const auto &b) { return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]); });
        vector<vector<int>> res;
        res.reserve(people.size());
        for (const auto &p : people)
            res.insert(res.begin() + p[1], p);
        return res;
    }
};
