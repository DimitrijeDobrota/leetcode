class Solution {
  public:
    int leastInterval(vector<char> &tasks, int n) {
        if (n == 0) return tasks.size();

        vector<int> count(26);
        for (char t : tasks)
            count[t - 'A']++;

        int maxi = INT_MIN, cnt = 0;
        for (int n : count) {
            if (n == maxi)
                cnt++;
            else if (n > maxi) {
                maxi = n;
                cnt = 1;
            }
        }

        return max((int)tasks.size(), (maxi - 1) * (n + 1) + cnt);
    }
};
