class Solution {
  public:
    int maxOperations(const string &s) const {
        const int n = size(s);
        int res = 0, count = 0;

        for (int i = 0; i < n;) {
            const int start = i;

            while (i < n && s[i] == s[start])
                i++;

            if (s[start] == '0')
                res += count;
            else
                count += i - start;
        }
        return res;
    }
};
