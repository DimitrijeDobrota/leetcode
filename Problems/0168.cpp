class Solution {
  public:
    string convertToTitle(int columnNumber) {
        string res = "";
        do {
            columnNumber -= 1;
            res += 'A' + columnNumber % 26;
        } while ((columnNumber /= 26));
        reverse(res.begin(), res.end());
        return res;
    }
};
