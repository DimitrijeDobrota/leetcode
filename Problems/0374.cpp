class Solution {
public:
  int guessNumber(int n) {
    int low = 1, high = n;
    while (true) {
      int mid = low + (high - low) / 2;
      switch (guess(mid)) {
      case 0: return mid;
      case 1: low = mid + 1; break;
      case -1: high = mid - 1; break;
      default: return -1;
      }
    }
    return -1;
  }
};
