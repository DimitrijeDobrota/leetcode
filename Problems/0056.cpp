class Solution {
  typedef vector<int> interval;

public:
  vector<interval> merge(vector<interval> &intervals) {
    auto cmp = [](const interval &i1, const interval &i2) {
      return i1[0] < i2[0];
    };
    sort(intervals.begin(), intervals.end(), cmp);

    vector<interval> res;
    int start = intervals[0][0], end = intervals[0][1];
    for (auto &i : intervals) {
      if (i[0] > end) {
        res.push_back({start, end});
        start = i[0];
      }
      end = max(end, i[1]);
    }

    if (res.empty() || res.back()[1] != end) res.push_back({start, end});

    return res;
  }
};
