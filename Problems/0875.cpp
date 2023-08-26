class Solution {
  public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int low = 1, high = INT_MAX, mid, count;
        while (low < high) {
            mid = low + (high - low) / 2, count = 0;
            for (int pile : piles)
                count += ceil((double)pile / mid);
            if (count <= h)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};
