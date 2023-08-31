class Solution {
  public:
    int minTaps(int n, const vector<int> &ranges) {
        vector<int> reach(n + 1);
        for (int i = 0; i < ranges.size(); i++) {
            int start = max(i - ranges[i], 0);
            int end = min(n, i + ranges[i]);
            reach[start] = max(reach[start], end);
        }

        int res = 0, crnt = 0, next = 0;
        for (int i = 0; i <= n; i++) {
            if (i > next) return -1;
            if (i > crnt) {
                res++;
                crnt = next;
            }
            next = max(next, reach[i]);
        }

        return res;
    }
};
