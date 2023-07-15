// Recursive, top down
class Solution {
  typedef vector<int> Event;
  vector<vector<int>> dp;

  int rec(const vector<Event> &events, const vector<Event>::const_iterator it,
          int k) {
    static const auto cmp = [](const Event &a, int val) { return a[0] <= val; };

    if (!k || it == events.end()) return 0;
    int idx = distance(events.begin(), it);
    if (dp[k][idx] != -1) return dp[k][idx];

    auto next = lower_bound(it, events.end(), (*it)[1], cmp);
    int with = (*it)[2] + rec(events, next, k - 1);
    int without = rec(events, it + 1, k);
    return dp[k][idx] = max(with, without);
  }

public:
  int maxValue(vector<Event> &events, int k) {
    static const auto cmp = [](const Event &a, const Event &b) {
      return a[0] < b[0];
    };
    sort(events.begin(), events.end(), cmp);

    dp = vector(k + 1, vector(events.size(), -1));
    return rec(events, events.begin(), k);
  }
};

// Iterative, bottom up
class Solution {
  typedef vector<int> Event;

public:
  int maxValue(vector<Event> &events, int k) {
    static const auto cmp = [](const Event &a, int val) { return a[0] <= val; };
    static const auto cmp_sort = [](const Event &a, const Event &b) {
      return a[0] < b[0];
    };
    sort(events.begin(), events.end(), cmp_sort);

    vector<vector<int>> dp(k + 1, vector(events.size() + 1, 0));

    auto start = events.rbegin();
    for (int i = events.size() - 1; i >= 0; i--, start++) {
      auto it = lower_bound(start.base(), events.end(), events[i][1], cmp);
      int offset = distance(events.begin(), it);
      for (int cnt = 1; cnt <= k; cnt++) {
        dp[cnt][i] = max(dp[cnt][i + 1], events[i][2] + dp[cnt - 1][offset]);
      }
    }

    return dp[k][0];
  }
};
