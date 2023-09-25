class Solution {
  public:
    char findTheDifference(const string &s, const string &t) {
        int sum = 0;
        for (const char c : t)
            sum += c;
        for (const char c : s)
            sum -= c;
        return sum;
    }
};
