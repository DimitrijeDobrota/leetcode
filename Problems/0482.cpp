class Solution {
  public:
    string licenseKeyFormatting(const string &s, int k) const {
        const int n = std::count(begin(s), end(s), '-');
        const int m = size(s) - n;

        string res;
        int goal = m % k ? m % k + 1 : k + 1;
        for (const char c : s) {
            if (c == '-') continue;
            if (!--goal) res += '-', goal = k;

            res += toupper(c);
        }

        return res;
    }
};
