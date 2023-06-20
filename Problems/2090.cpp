class Solution {
public:
  vector<int> getAverages(const vector<int> &nums, int k) {
    int n = nums.size();
    if (n <= 2 * k) return vector<int>(n, -1);

    vector<int> res(n);
    long long sum = 0;
    for (int i = 0; i < k; i++) {
      sum += nums[i] + nums[i + k];
      res[i] = res[n - k + i] = -1;
    }

    for (int i = k; i < n - k; i++) {
      sum += nums[i + k];
      res[i] = sum / (2 * k + 1);
      sum -= nums[i - k];
    }

    return res;
  }
};
