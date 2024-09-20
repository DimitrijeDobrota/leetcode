class Solution {
  public:
    string shortestPalindrome(const string &s) const {
        const int n = s.size();
        int i = 0, j = n - 1;

        while (j >= 0) {
            if (s[i] == s[j]) i++;
            j--;
        }

        if (i == n) return s;
        string remain = s.substr(i), rev = remain;
        reverse(rev.begin(), rev.end());

        return rev + shortestPalindrome(s.substr(0, i)) + remain;
    }
};
