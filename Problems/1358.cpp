class Solution {
  public:
    int numberOfSubstrings(const string &s) {
        int st[3] = {0}, count = 0, res = 0, left = 0;
        for (int i = 0; i < s.size(); i++) {
            if (!st[s[i] - 'a']++) count++;
            while (count == 3) {
                res += s.size() - i;
                if (!--st[s[left++] - 'a']) count--;
            }
        }
        return res;
    }
};
