class Solution {
  public:
    string decodeAtIndex(const string &s, int k) {
        long n = 0, idx;

        for (idx = 0; n < k; idx++) {
            n = isdigit(s[idx]) ? n * (s[idx] & 0x0F) : n + 1;
        }

        while (idx--) {
            if (isdigit(s[idx]))
                n /= s[idx] & 0x0F, k %= n;
            else if (k % n == 0)
                return string(1, s[idx]);
            else
                n--;
        }
        return "";
    }
};
