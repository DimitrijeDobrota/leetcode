class Solution {
  public:
    string baseNeg2(int n) {
        if (n == 0) return "0";
        string res;
        do {
            res += to_string(n & 1);
        } while ((n = -(n >> 1)));
        reverse(begin(res), end(res));
        return res;
    }
};
