class Solution {
  public:
    long long minimumPerimeter(const long long neededApples) const {
        long long low = 1, high = 100000;
        while (low < high) {
            const long long mid = (low + high) / 2;
            const long long count = 4 * mid * mid * mid + 6 * mid * mid + 2 * mid;
            if (count >= neededApples)
                high = mid;
            else
                low = mid + 1;
        }
        return low * 8;
    }
};
