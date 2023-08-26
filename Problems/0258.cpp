class Solution {
  public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            do {
                sum += num % 10;
            } while ((num /= 10) > 0);
            num = sum;
        }
        return num;
    }
};
