class Solution {
  public:
    int hIndex(const vector<int> &citations) const {
        const int n = size(citations);
        int low = 0, high = n - 1;

        while (low <= high) {
            const int mid = low + (high - low) / 2;
            if (citations[mid] == n - mid) return citations[mid];
            if (citations[mid] > n - mid)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return n - high - 1;
    }
};
