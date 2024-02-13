class Solution {
    static bool isPalindrome(const string &s) {
        int i = 0, j = size(s) - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

  public:
    string firstPalindrome(const vector<string> &words) const {
        for (const string &word : words) {
            if (isPalindrome(word)) return word;
        }
        return "";
    }
};
