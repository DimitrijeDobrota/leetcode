class Solution {
    typedef vector<int> interval;

  public:
    int eraseOverlapIntervals(vector<interval> &intervals) {
        auto cmp = [](const interval &i1, const interval &i2) { return i1[1] < i2[1]; };
        sort(intervals.begin(), intervals.end(), cmp);

        int end = intervals[0][1], count = 1;
        for (auto &i : intervals) {
            if (i[0] >= end) {
                end = i[1];
                count++;
            }
        }
        return intervals.size() - count;
    }
};
