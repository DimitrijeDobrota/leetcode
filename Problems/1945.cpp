class Solution {
    static int sum(int n) {
        int res = 0;

        while (n > 0) {
            res += n % 10;
            n /= 10;
        }

        return res;
    }

  public:
    int getLucky(const string &s, int k) const {
        int res = 0;

        for (const char c : s)
            res += sum(c - '`');
        for (int i = 1; i < k; i++)
            res = sum(res);

        return res;
    }
};
