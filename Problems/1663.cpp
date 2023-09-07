class Solution {
  public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        int full = (k - n) / 25, extra = (k - n) % 25;
        for (int i = 0; i < full; i++)
            res[n - i - 1] = 'z';
        if (extra) res[n - full - 1] += extra;
        return res;
    }
};
