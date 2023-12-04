class Solution {
  public:
    string largestGoodInteger(const string &num) const {
        int res = -1;
        for (int i = 0; i < num.size() - 2; i++) {
            if (num[i] == num[i + 1] && num[i] == num[i + 2]) {
                res = max(res, num[i] & 0x0F);
            }
        }
        return res == -1 ? "" : string(3, '0' + res);
    }
};
