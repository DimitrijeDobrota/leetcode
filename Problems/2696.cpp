class Solution {
  public:
    int minLength(string s) const {
        int n = size(s);
        while (true) {
            int j = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == 'A' && s[i + 1] == 'B')
                    i++;
                else if (s[i] == 'C' && s[i + 1] == 'D')
                    i++;
                else
                    s[j++] = s[i];
            }

            if (j == n) break;
            s[n = j] = '\0';
        }

        return n;
    }
};
