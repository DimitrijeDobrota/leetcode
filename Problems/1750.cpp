class Solution {
  public:
    int minimumLength(const string &s) const {
        int i = 0, j = size(s) - 1;
        while (i < j && s[i] == s[j]) {
            const int goal = s[i];
            while (i <= j && s[i] == goal)
                i++;
            while (i < j && s[j] == goal)
                j--;
        }

        return j - i + 1;
    }
};
