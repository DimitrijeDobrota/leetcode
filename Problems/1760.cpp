class Solution {
  public:
    int minimumSize(const vector<int> &nums, const int maxOperations) const {
        int low = 1, high = 1E9;
        while (low <= high) {
            const int mid = low + (high - low) / 2;
            int op = 0;
            for (const int n : nums)
                op += (n - 1) / mid;
            if (op > maxOperations)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low;
    }
};
