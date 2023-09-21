class Solution {
  public:
    int beautySum(const string &s) {
        int res = 0;
        for (auto i = 0; i < s.size(); i++) {
            int cnt[27] = {0}, maxi = 0, mini = 0;
            for (auto j = i; j < s.size(); j++) {
                const int idx = s[j] & 0x1F;
                maxi = max(maxi, ++cnt[idx]);
                if (mini >= cnt[idx] - 1) {
                    mini = cnt[idx];
                    for (int k = 1; k <= 26; ++k)
                        mini = min(mini, cnt[k] == 0 ? INT_MAX : cnt[k]);
                }
                res += maxi - mini;
            }
        }
        return res;
    }
};
