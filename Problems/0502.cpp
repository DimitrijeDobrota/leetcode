class Solution {
  typedef pair<int, int> pii;

public:
  int findMaximizedCapital(int k, int w, vector<int> &profits,
                           vector<int> &capital) {
    vector<pii> data(profits.size());
    for (int i = 0; i < profits.size(); i++) data[i] = {capital[i], profits[i]};
    sort(data.begin(), data.end());

    auto cmp = [](const pii &a, const pii &b) { return a.second < b.second; };
    priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

    int i = 0;
    while (i < profits.size() && k) {
      if (data[i].first <= w)
        pq.push(data[i++]);
      else {
        while (!pq.empty() && data[i].first > w && k) {
          w += pq.top().second;
          pq.pop();
          k--;
        }
        if (pq.empty() && data[i].first > w) break;
      }
    }
    while (!pq.empty() && k) {
      w += pq.top().second;
      pq.pop();
      k--;
    }

    return w;
  }
};
