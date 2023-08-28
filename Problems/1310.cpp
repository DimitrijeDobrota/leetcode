class Solution {
  public:
    vector<int> xorQueries(const vector<int> &arr, const vector<vector<int>> &q) {
        const int n = arr.size(), m = q.size();
        vector<int> sum(n + 1), res(m);
        for (int i = 0, acc = 0; i < n; i++)
            sum[i + 1] = acc ^= arr[i];
        for (int i = 0; i < m; i++)
            res[i] = sum[q[i][1] + 1] ^ sum[q[i][0]];
        return res;
    }
};
