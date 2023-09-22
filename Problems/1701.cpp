class Solution {
  public:
    double averageWaitingTime(const vector<vector<int>> &customers) {
        const int n = customers.size();
        double time = 0, res = 0;
        for (int i = 0; i < n; i++) {
            if (time < customers[i][0])
                time = customers[i][0];
            else
                res += time - customers[i][0];
            time += customers[i][1];
            res += customers[i][1];
        }
        return res / n;
    }
};
