class Solution {
  public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        int tmp;

        while (n != 1 && !seen.count(n)) {
            seen.insert(n);
            tmp = n, n = 0;
            do {
                n += (tmp % 10) * (tmp % 10);
            } while ((tmp /= 10) > 0);
        }
        return !seen.count(n);
    }
};
