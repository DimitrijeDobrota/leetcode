class Solution {
  public:
    int minSpeedOnTime(vector<int> &dist, double hour) {
        int low = 1, high = 10000000;
        int res = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            double time = 0;
            for (int i = 0; i < dist.size() - 1; i++)
                time += ceil((double)dist[i] / mid);
            time += (double)dist.back() / mid;
            if (time <= hour) {
                res = mid;
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return res;
    }
};
