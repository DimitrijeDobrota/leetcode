class Solution {
  public:
    vector<int> numsSameConsecDiff(const int n, const int k) const {
        static const int lookup[] = {0,      1,       10,       100,       1000,      10000,
                                     100000, 1000000, 10000000, 100000000, 1000000000};
        vector<int> res;
        queue<int> q;
        for (int i = 1; i <= 9; i++)
            q.push(i);
        while (!q.empty()) {
            const int crnt = q.front();
            q.pop();
            if (crnt >= lookup[n])
                res.push_back(crnt);
            else {
                const int low = crnt % 10 - k, high = crnt % 10 + k;
                if (high <= 9) q.push(crnt * 10 + high);
                if (k == 0) continue;
                if (low >= 0) q.push(crnt * 10 + low);
            }
        }
        return res;
    }
};
