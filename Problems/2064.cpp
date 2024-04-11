class Solution {
  public:
    int minimizedMaximum(const int n, const vector<int> &quantities) const {
        int low = 1, high = 100000;

        while (low <= high) {
            int mid = low + (high - low) / 2, count = 0;
            for (const int q : quantities)
                count += (q + mid - 1) / mid;

            if (count <= n)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};
