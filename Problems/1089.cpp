class Solution {
public:
  void duplicateZeros(vector<int> &arr) {
    int cnt = 0;
    int len = arr.size() - 1;
    for (int i = 0; i + cnt <= len; i++)
      if (arr[i] == 0) {
        if (i + cnt == len) {
          arr[len] = 0;
          len -= 1;
          break;
        }
        cnt++;
      }

    for (int i = len - cnt; i >= 0; i--) {
      if (arr[i] == 0) {
        arr[i + cnt] = 0;
        cnt--;
        arr[i + cnt] = 0;
      } else {
        arr[i + cnt] = arr[i];
      }
    }
  }
};
