class Solution {
  int dp[2001][2001][2];

  void norm(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    int i = 1, j = 1;
    while (i < arr.size()) {
      if (arr[i] != arr[i - 1]) arr[j++] = arr[i];
      i++;
    }
    arr.resize(j);
  }

  int rec(const vector<int> &arr1, const vector<int> &arr2, int i, int j,
          bool other) {
    if (i >= arr1.size()) return 0;
    int prev = !other ? i == 0 ? INT_MIN : arr1[i - 1] : arr2[j];
    j = upper_bound(arr2.begin() + j, arr2.end(), prev) - arr2.begin();
    if (dp[i][j][other]) return dp[i][j][other];

    int res = 2002;
    if (j < arr2.size()) res = rec(arr1, arr2, i + 1, j, true) + 1;
    if (prev < arr1[i]) res = min(res, rec(arr1, arr2, i + 1, j, false));
    return dp[i][j][other] = res;
  }

public:
  int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
    norm(arr2);
    int res = rec(arr1, arr2, 0, 0, false);
    return res >= 2002 ? -1 : res;
  }
};
