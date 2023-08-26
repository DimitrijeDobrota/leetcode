class Solution {
  public:
    int minAddToMakeValid(const string &s) {
        int res = 0, cnt = 0;
        for (char c : s) {
            if (c == '(')
                cnt++;
            else if (c == ')') {
                if (cnt > 0)
                    cnt--;
                else
                    res++;
            }
        }
        return res + cnt;
    }
};
