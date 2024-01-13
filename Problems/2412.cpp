static const auto _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return NULL;
}();

class Solution {
  public:
    int longestContinuousSubstring(const string &s) const {
        int res = 0, crnt = 1;
        for (int i = 1; i < size(s); i++) {
            if (s[i] - s[i - 1] == 1)
                crnt++;
            else {
                res = max(res, crnt);
                crnt = 1;
            }
        }
        return max(res, crnt);
    }
};
