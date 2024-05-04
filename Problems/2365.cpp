class Solution {
  public:
    long long taskSchedulerII(const vector<int> &tasks, int space) const {
        unordered_map<int, long long> um;
        long long day = 0;

        for (const int t : tasks) {
            um[t] = day = max(day, um[t] + space) + 1;
        }

        return day - space;
    }
};
