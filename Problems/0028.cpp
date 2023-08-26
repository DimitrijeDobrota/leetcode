class Solution {
  public:
    int strStr(string haystack, string needle) {
        vector<int> table(needle.size(), 0);

        int m = haystack.size(), n = needle.size();
        for (int len = 0, j = 1; j < n;) {
            if (needle[j] == needle[len])
                table[j++] = ++len;
            else if (len)
                len = table[len - 1];
            else
                table[j++] = 0;
        }

        for (int i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) i++, j++;
            if (j == n) return i - j;
            if (i < m && haystack[i] != needle[j]) j ? j = table[j - 1] : i++;
        }

        return -1;
    }
};
