class Solution {
public:
  long long minimumTime(vector<int> &time, int totalTrips) {
    long long low = 1, high = 1e14, mid, count;
    while (low < high) {
      mid = low + (high - low) / 2, count = 0;
      for (long long t : time) count += mid / t;
      if (count >= totalTrips)
        high = mid;
      else
        low = mid + 1;
    }
    return low;
  }
};
