class Solution {
  public:
    string makeFancyString(string &s) const {
        char prev = '\0';
        int i = 0, cnt = 0;

        for (const char c : s) {
            if (c == prev)
                cnt++;
            else
                prev = c, cnt = 1;
            if (cnt <= 2) s[i++] = c;
        }

        s.resize(i);
        return s;
    }
};
