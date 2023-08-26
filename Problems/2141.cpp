class Solution {
  public:
    long long maxRunTime(int n, const vector<int> &batteries) {
        long long low = 1, high = reduce(batteries.begin(), batteries.end(), 0LL) / n;
        while (low < high) {
            long long mid = high - (high - low) / 2, sum = 0;
            for (long long bat : batteries)
                sum += min(bat, mid);
            if (sum >= (long long)(n * mid))
                low = mid;
            else
                high = mid - 1;
        }
        return low;
    }
};
