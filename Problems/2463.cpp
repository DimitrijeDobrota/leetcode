class Solution {
  public:
    long long minimumTotalDistance(vector<int> &robot, vector<vector<int>> &factory) const {
        sort(begin(factory), end(factory));
        sort(begin(robot), end(robot));

        vector<int> positions;
        for (const auto &f : factory) {
            for (int i = 0; i < f[1]; i++) {
                positions.push_back(f[0]);
            }
        }

        const int n = size(robot), m = size(positions);
        static long long dp[10001];

        memset(dp, 0x00, sizeof(dp));
        dp[m] = 1e12;
        for (int i = n - 1; i >= 0; i--) {
            long long prev = i != n - 1 ? 1e12 : 0;
            for (int j = m - 1; j >= 0; j--) {
                long long assign = abs(robot[i] - positions[j]) + prev;
                long long skip = dp[j + 1];

                prev = dp[j];
                dp[j] = min(assign, skip);
            }
        }

        return dp[0];
    }
};
