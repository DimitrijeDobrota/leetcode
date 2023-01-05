class Solution {
public:
  int closestMeetingNode(vector<int> &e, int node1, int node2) {
    const int n = e.size();
    vector<int> d(n, -1);

    for (int i = node1, di = 0; i != -1 && d[i] == -1; i = e[i]) d[i] = di++;

    int res = -1, mini = INT_MAX;
    for (int i = node2, di = 0; i != -1 && d[i] != -2; i = e[i], di++) {
      int t = max(d[i], di);
      if (d[i] != -1 && t <= mini) {
        if (t < mini)
          res = i;
        else
          res = min(res, i);
        mini = t;
      }
      d[i] = -2;
    }

    return res;
  }
};
