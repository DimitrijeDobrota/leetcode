class Solution {
  public:
    int countSubstrings(const string &s) {
        const int size = s.size();
        int res = size, low, high;
        for (int i = 0; i < size; i++) {
            low = i - 1, high = i + 1;
            while (low >= 0 && high < size) {
                if (s[low--] != s[high++]) break;
                res++;
            }

            low = i - 1, high = i;
            while (low >= 0 && high < size) {
                if (s[low--] != s[high++]) break;
                res++;
            }
        }
        return res;
    }
};
