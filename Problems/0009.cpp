class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int sum = 0;
        do {
            sum = sum * 10 + x % 10;
        } while ((x /= 10) > sum);
        return (x == sum) || (x == sum / 10);
    }
};
