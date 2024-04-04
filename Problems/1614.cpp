class Solution {
  public:
    int maxDepth(const string &s) const {
        int res = 0, cnt = 0;

        for (const char c : s) {
            if (c == '(')
                cnt++;
            else if (c == ')')
                res = max(res, cnt--);
        }

        return res;
    }
};
