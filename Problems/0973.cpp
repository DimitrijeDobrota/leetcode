class Solution {
  typedef pair<double, int> pdi;

public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    auto cmp = [](const pdi &a, const pdi &b) { return a.first < b.first; };
    priority_queue<pdi, vector<pdi>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < points.size(); i++) {
      pq.push({sqrt(pow(points[i][0], 2) + pow(points[i][1], 2)), i});
      if (pq.size() > k) pq.pop();
    }

    vector<vector<int>> res(k);
    while (k--) res[k] = points[pq.top().second], pq.pop();
    return res;
  }
};
