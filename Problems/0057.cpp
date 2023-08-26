class Solution {
    typedef vector<int> Interval;

  public:
    vector<Interval> insert(vector<Interval> &intervals, Interval &newInterval) {
        if (intervals.empty()) return {newInterval};

        vector<Interval> res;
        int n = intervals.size(), i = 0;
        for (; i < n && intervals[i][1] < newInterval[0]; i++) {
            res.push_back(intervals[i]);
        }

        for (; i < n && newInterval[1] >= intervals[i][0]; i++) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
        }

        res.push_back(newInterval);

        for (; i < n; i++) {
            res.push_back(intervals[i]);
        }

        return res;
    }
};
