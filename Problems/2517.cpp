class Solution {
  public:
    int maximumTastiness(vector<int> &price, int k) {
        sort(begin(price), end(price));
        int low = 0, high = price.back() - price.front();
        while (low <= high) {
            int mid = low + (high - low) / 2, cnt = 1;
            for (int i = 1, j = 0; i < price.size(); i++) {
                if (price[i] - price[j] >= mid) cnt++, j = i;
            }
            if (cnt >= k)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};
