class Solution {
  public:
    int subtractProductAndSum(int n) const {
        int product = 1, sum = 0;

        do {
            const int digit = n % 10;
            product *= digit;
            sum += digit;
        } while ((n /= 10) > 0);

        return product - sum;
    }
};
