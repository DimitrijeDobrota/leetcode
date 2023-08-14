class Solution {
public:
  vector<int> processQueries(const vector<int> &queries, int m) {
    vector<int> vec(m), res;
    res.reserve(queries.size());
    iota(vec.begin(), vec.end(), 1);
    for (const int query : queries) {
      int i = 0, tmp = query;
      while (vec[i] != query) swap(tmp, vec[i++]);
      vec[i] = tmp;
      res.push_back(i);
    }
    return res;
  }
};
