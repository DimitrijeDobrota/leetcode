class Solution {
  public:
    string maximumOddBinaryNumber(const string &s) const {
        const int n = size(s);
        string res(n, '0');
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') res[cnt++] = '1';
        }
        if (cnt == n) return s;
        res[--cnt] = '0', res.back() = '1';
        return res;
    }
};
