class Solution {
public:
  typedef pair<int, int> ii;
  vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
    vector<ii> vp;

    int i = 0;
    for (auto &v : mat)
      vp.push_back(make_pair(i++, accumulate(v.begin(), v.end(), 0)));

    sort(vp.begin(), vp.end(), [](const ii &a, const ii &b) -> bool {
      return a.second < b.second || (a.second == b.second && a.first < b.first);
    });

    vector<int> res;
    for (auto &p : vp)
      if (k--)
        res.push_back(p.first);
      else
        break;

    return res;
  }
};
