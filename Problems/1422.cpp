class Solution {
  public:
    int maxScore(const string &s) const {
        int res = 0, zero = 0, one = count(begin(s), end(s), '1');
        for (int i = 0; i < size(s) - 1; i++) {
            if (s[i] == '1')
                one--;
            else
                zero++;
            res = max(res, zero + one);
        }
        return res;
    }
};
