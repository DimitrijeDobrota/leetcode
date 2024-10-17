class Solution {
  public:
    int countSegments(const string &s) const {
        const int n = size(s);
        int res = 0;

        for (int i = 0; i < n;) {
            if (s[i] != ' ') {
                while (i < n && s[i] != ' ')
                    i++;
                res++;
            } else {
                while (i < n && s[i] == ' ')
                    i++;
            }
        }

        return res;
    }
};
