class Solution {
  public:
    vector<int> findRightInterval(const vector<vector<int>> &intervals) const {
        const int n = size(intervals);
        vector<int> res(n);
        map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[intervals[i][0]] = i;
        for (int i = 0; i < n; i++) {
            const auto it = mp.lower_bound(intervals[i][1]);
            res[i] = it != mp.end() ? it->second : -1;
        }

        return res;
    }
};
