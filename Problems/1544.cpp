class Solution {
  public:
    string makeGood(string s) {
        int i = 0;
        while (i < s.size())
            if (s[i] != s[i + 1] && toupper(s[i]) == toupper(s[i + 1])) {
                s.erase(i, 2);
                i = max(0, i - 1);
            } else {
                i++;
            }
        return s;
    }
};
