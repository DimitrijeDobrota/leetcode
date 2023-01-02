class Solution {
public:
  int edgeScore(vector<int> &edges) {
    vector<long long> score(edges.size(), 0);
    long long maxi = LONG_MIN;
    int index = -1;

    for (int i = 0; i < edges.size(); i++) {
      score[edges[i]] += i;
      if (score[edges[i]] > maxi) {
        maxi = score[edges[i]];
        index = edges[i];
      } else if (score[edges[i]] == maxi)
        index = min(index, edges[i]);
    }

    return index;
  }
};
