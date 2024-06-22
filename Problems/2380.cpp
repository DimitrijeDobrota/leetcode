class Solution {
  public:
    int secondsToRemoveOccurrences(const string &s) const {
        int res = 0, count = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0')
                count++;
            else if (count)
                res = max(res + 1, count);
        }

        return res;
    }
};
