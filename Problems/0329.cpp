class Solution {
  public:
    int longestIncreasingPath(const vector<vector<int>> &matrix) const {
        const int n = size(matrix), m = size(matrix[0]);

        static const int offset[] = {-1, 0, 1, 0, -1};
        const auto valid = [&](int i, int j) { return i >= 0 && i < n && j >= 0 && j < m; };

        static int dp[201][201];
        memset(dp, 0xFF, sizeof(dp));

        int res = 0;
        stack<tuple<int, int>> st;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dp[i][j] != -1) continue;

                st.emplace(i, j);
                while (!st.empty()) {
                    if (get<0>(st.top()) != -1) {
                        const auto [i, j] = st.top();
                        if (dp[i][j] != -1) {
                            st.pop();
                            continue;
                        }

                        dp[i][j] = -3;
                        st.emplace(-1, -1);
                        for (int k = 0; k < 4; k++) {
                            const int a = i + offset[k + 1];
                            const int b = j + offset[k];

                            if (!valid(a, b) || matrix[i][j] >= matrix[a][b]) continue;
                            if (dp[a][b] != -1) continue;
                            st.emplace(a, b);
                            dp[i][j] = -2;
                        }

                        continue;
                    }

                    st.pop();
                    const auto [i, j] = st.top();
                    st.pop();

                    int res = 0;
                    for (int k = 0; k < 4; k++) {
                        const int a = i + offset[k + 1];
                        const int b = j + offset[k];

                        if (!valid(a, b) || matrix[i][j] >= matrix[a][b]) continue;
                        res = max(res, dp[a][b]);
                    }

                    dp[i][j] = res + 1;
                }

                res = max(res, dp[i][j]);
            }
        }

        return res;
    }
};
