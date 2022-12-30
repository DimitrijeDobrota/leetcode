class Solution {
  struct item {
    int index, et, pt;
    item(int i, int e, int p) : index(i), et(e), pt(p) {}
    friend bool operator<(const item &i1, const item &i2) {
      return (i1.pt > i2.pt) || (i1.pt == i2.pt && i1.index > i2.index);
    }
  };

public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    vector<item> ss;
    for (int i = 0; i < tasks.size(); i++)
      ss.push_back({i, tasks[i][0], tasks[i][1]});
    sort(ss.begin(), ss.end(),
         [](const item &i1, const item &i2) { return (i1.et < i2.et); });

    vector<int> res;
    priority_queue<item> pq;
    int t = 0;
    for (int i = 0; i < ss.size();) {
      if (pq.empty() && t < ss[i].et) t = ss[i].et;
      while (i < ss.size() && ss[i].et <= t) pq.push(ss[i++]);
      item it = pq.top();
      pq.pop();
      res.push_back(it.index);
      t += it.pt;
    }
    while (!pq.empty()) res.push_back(pq.top().index), pq.pop();
    return res;
  }
};
