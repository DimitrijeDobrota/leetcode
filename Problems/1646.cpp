class Solution {
public:
  int getMaximumGenerated(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    vector<int> vec(n + 1);
    vec[0] = 0;
    vec[1] = 1;

    int maxi = 0;
    for (int i = 2; i <= n; i++) {
      vec[i] = vec[i / 2];
      if (i % 2) vec[i] += vec[i / 2 + 1];
      maxi = max(vec[i], maxi);
    }

    return maxi;
  }
};
