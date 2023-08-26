class Solution {
  public:
    int maxValue(int n, int index, int maxSum) {
        const int a = index, b = n - index - 1;
        int low = 0, high = maxSum;

        const auto arit = [](long n, int mid) { return (long)n * mid - n * (n + 1) / 2; };
        while (low < high) {
            int mid = (low + high + 1) / 2;
            long res = mid + arit(min(a, mid - 1), mid) + arit(min(b, mid - 1), mid);
            if (res <= maxSum - n)
                low = mid;
            else
                high = mid - 1;
        }
        return low + 1;
    }
};
