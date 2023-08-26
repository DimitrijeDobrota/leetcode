class Solution {
  public:
    int titleToNumber(string columnTitle) {
        int res = 0;
        for (char c : columnTitle) {
            res *= 26;
            res += c - 'A' + 1;
        }
        return res;
    }
};
