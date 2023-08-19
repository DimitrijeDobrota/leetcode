class Solution {
public:
  int countTriplets(const vector<int> &arr) {
    static int left[301];
    left[0] = 0;
    int n = arr.size(), res = 0;

    for (int i = 0, acc = 0; i < n; i++) left[i + 1] = acc ^= arr[i];

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (left[i] == left[j + 1]) res += j - i;
      }
    }

    return res;
  }
};
