class Solution {
  public:
    int removeCoveredIntervals(vector<vector<int>> &intervals) const {
        const int n = size(intervals);

        sort(begin(intervals), end(intervals),
             [](const auto &a, const auto &b) { return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1]; });

        int res = 0, right = 0;
        for (int i = 0; i < n; i++) {
            if (intervals[i][1] <= right) continue;
            right = intervals[i][1];
            res++;
        }
        return res;
    }
};
