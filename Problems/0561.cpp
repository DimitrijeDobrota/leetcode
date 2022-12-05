class Solution {
  const static int length = 20001;

public:
  int arrayPairSum(vector<int> &nums) {
    int arr[length] = {0};

    for (int i : nums) arr[i + 10000]++;

    int res = 0;
    int sub = 0;
    for (int i = 0; i < length; i++) {
      if (!arr[i]) continue;

      arr[i] -= sub;
      res += (arr[i] / 2 + arr[i] % 2) * (i - 10000);
      sub = arr[i] % 2;
    }
    return res;
  }
};
