class Solution {
  public:
    long long numberOfWays(const string &s) const {
        static int count[100001];
        const int n = size(s);
        int crnt[] = {0, 0};
        long long res = 0;

        for (int i = n - 1; i >= 0; i--) {
            const int idx = s[i] - '0';
            count[i] = crnt[!idx];
            crnt[idx]++;
        }

        crnt[0] = crnt[1] = 0;
        for (int i = 0; i < n; i++) {
            const int idx = s[i] - '0';
            res += count[i] * crnt[!idx];
            crnt[idx]++;
        }

        return res;
    }
};
