class Solution {
  public:
    int minInsertions(string s) const {
        const int n = size(s);
        int res = 0, cnt = 0;

        s.push_back(' ');
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                cnt++;
            else {
                if (cnt) {
                    if (s[i + 1] == ')')
                        i++;
                    else
                        res++;
                    cnt--;
                } else {
                    if (s[i + 1] == ')')
                        res++, i++;
                    else
                        res += 2;
                }
            }
        }

        return res + cnt * 2;
    }
};
