class Solution {
  public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>> &logs, int k) {
        sort(logs.begin(), logs.end());

        vector<int> res(k, 0);
        int crnt = logs.front()[0], val = logs.front()[1], count = 1;
        for (const auto &log : logs) {
            if (log[0] == crnt) {
                if (log[1] == val) continue;
                val = log[1];
                count++;
            } else {
                if (count >= 1 && count <= k) res[count - 1]++;
                crnt = log[0];
                val = log[1];
                count = 1;
            }
        }
        if (count >= 1 && count <= k) res[count - 1]++;
        return res;
    }
};
