class Solution {
  public:
    int reachNumber(int target) const {
        target = abs(target);

        const long long n = ceil((sqrt(1 + 8.0 * target) - 1.0) / 2);
        const long long sum = n * (n + 1) / 2;

        if (sum == target) return n;
        const long long res = sum - target;

        if (res % 2 == 0) return n;
        return n + (n % 2 == 1) + 1;
    }
};
