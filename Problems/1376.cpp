class Solution {
  public:
    int numOfMinutes(int n, int headID, const vector<int> &manager, const vector<int> &informTime) {
        vector<int> time(n, -1);
        time[headID] = 0;
        int res = 0, crnt, sum1, sum2;
        for (int i = 0; i < n; i++) {
            if (informTime[i] != 0) continue;
            crnt = i, sum1 = 0;
            while (time[crnt] == -1) {
                sum1 += informTime[crnt];
                crnt = manager[crnt];
            }
            res = max(res, sum1 += time[crnt]);
            crnt = i, sum2 = 0;
            while (time[crnt] == -1) {
                time[crnt] = sum1 - sum2;
                sum2 += informTime[crnt];
                crnt = manager[crnt];
            }
        }

        return res + informTime[headID];
    }
};
