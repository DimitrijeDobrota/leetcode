class Solution {
  public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        do {
            int ba = a & 1, bb = b & 1;
            if (c & 1)
                res += !(ba | bb);
            else
                res += ba + bb;
            a >>= 1, b >>= 1, c >>= 1;
        } while (a > 0 || b > 0 || c > 0);
        return res;
    }
};
