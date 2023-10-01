class Solution {
  public:
    int kthLargestValue(const vector<vector<int>> &matrix, int k) {
        static int crnt[1001], prev[1001];
        const int n = matrix.size(), m = matrix[0].size();
        priority_queue<int> pq;

        memset(prev, 0x00, sizeof(prev));
        for (int i = 0; i < n; i++) {
            memset(crnt, 0x00, sizeof(crnt));
            pq.push(crnt[0] = prev[0] ^ matrix[i][0]);
            for (int j = 1; j < m; j++) {
                crnt[j] = matrix[i][j] ^ prev[j] ^ crnt[j - 1] ^ prev[j - 1];
                pq.push(crnt[j]);
            }
            swap(prev, crnt);
        }

        while (--k)
            pq.pop();
        return pq.top();
    }
};
