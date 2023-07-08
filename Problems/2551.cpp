class Solution {
public:
  long long putMarbles(vector<int> &weights, int k) {
    long long res = 0, n = weights.size();

    for (int i = 0; i < n - 1; i++) weights[i] += weights[i + 1];

    weights.resize(n - 1);
    sort(weights.begin(), weights.end());

    for (int i = 0; i < k - 1; i++) res += weights[n - 2 - i] - weights[i];

    return res;
  }
};
