class Solution {
  public:
    int minFlipsMonoIncr(string s) {
        int res = 0, num = 0;
        for (char c : s)
            if (c == '0')
                res = min(num, res + 1);
            else
                ++num;
        return res;
    }
};
