class Solution {
  public:
    string breakPalindrome(string palindrome) const {
        const int n = size(palindrome);
        if (n == 1) return "";

        for (int i = 0; i < n / 2; i++) {
            if (palindrome[i] == 'a') continue;
            palindrome[i] = 'a';
            return palindrome;
        }

        palindrome[n - 1] = 'b';
        return palindrome;
    }
};
