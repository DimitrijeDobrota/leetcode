class Solution {
  public:
    bool queryString(const string &s, int n) {
        vector<bool> seen(n);
        int count = 0;
        for (int i = 0; i < size(s) && count < n; i++) {
            if (s[i] == '0') continue;
            for (int j = 0, crnt = 0; j < 30 && i + j < size(s) && crnt < n; j++) {
                crnt = (crnt << 1) + (s[i + j] & 1);
                if (crnt <= n && !seen[crnt]) seen[crnt] = ++count;
            }
        }
        return count == n;
    }
};
