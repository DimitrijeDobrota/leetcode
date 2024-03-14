class Solution {
  public:
    int numSteps(const string &s) const {
        int res = 0, add = 0;

        for (int i = size(s) - 1; i > 0; i--) {
            if (s[i] - '0' + add == 1) add = 1, res++;
            res++;
        }

        return res + add;
    }
};
