class Solution {
  public:
    string addBinary(string a, string b) {
        string res;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int add = 0;
        while (i >= 0 || j >= 0 || add) {
            if (i >= 0) add += a[i--] - '0';
            if (j >= 0) add += b[j--] - '0';
            res += to_string(add % 2);
            add /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
