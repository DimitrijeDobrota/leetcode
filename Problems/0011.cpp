class Solution {
public:
  int trap(vector<int> &height) {
    int ans = 0, n = height.size(), maxi, m1, m2;
    vector<int> mleft(n), mright(n);

    m1 = m2 = INT_MIN;
    for (int i = 0; i < n; i++) {
      mleft[i] = m1 = max(m1, height[i]);
      mright[n - i - 1] = m2 = max(m2, height[n - i - 1]);
    }

    for (int i = 1; i < n - 1; i++) ans += min(mleft[i], mright[i]) - height[i];
    return ans;
  }
};
