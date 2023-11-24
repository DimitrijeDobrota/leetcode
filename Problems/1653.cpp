class Solution {
  public:
    int minimumDeletions(const string &s) const {
        static int acount[100001];

        const int n = s.size();
        acount[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            acount[i] = acount[i + 1] + (s[i] == 'a');
        }

        int acnt = 0, bcnt = 0, res = acount[0];
        for (int i = 0; i < n; i++) {
            s[i] == 'a' ? acnt++ : bcnt++;
            res = min(res, bcnt + acount[i] - 1);
        }

        return res;
    }
};
