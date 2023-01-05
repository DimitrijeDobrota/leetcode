class Solution {
  typedef vector<int> segment;

public:
  int findMinArrowShots(vector<segment> &segments) {
    auto cmp = [](const segment &a, const segment &b) { return a[1] < b[1]; };
    sort(segments.begin(), segments.end(), cmp);
    int res = 1, arrow = segments[0][1];
    for (segment &s : segments) {
      if (s[0] > arrow) {
        res++;
        arrow = s[1];
      }
    }
    return res;
  }
};
