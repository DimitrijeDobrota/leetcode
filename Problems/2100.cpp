class Solution {
  public:
    vector<int> goodDaysToRobBank(const vector<int> &security, int time) const {
        static int up[100001], down[100001];
        const int n = size(security);

        if (time == 0) {
            vector<int> res(n);
            iota(begin(res), end(res), 0);
            return res;
        }

        up[0] = down[n - 1] = 0;
        for (int i = 0, cnt = 1; i < n - 1; i++) {
            if (security[i] >= security[i + 1])
                cnt++;
            else
                cnt = 0;
            up[i + 1] = cnt;
        }

        for (int i = n - 1, cnt = 0; i >= 1; i--) {
            if (security[i] >= security[i - 1])
                cnt++;
            else
                cnt = 0;
            down[i - 1] = cnt;
        }

        vector<int> res;
        for (int i = time; i < n - time; i++) {
            if (up[i] < time || down[i] < time) continue;
            if (security[i] > security[i - 1]) continue;
            if (security[i] > security[i + 1]) continue;

            res.emplace_back(i);
        }

        return res;
    }
};
