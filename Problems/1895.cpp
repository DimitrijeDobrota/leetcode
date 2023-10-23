class Solution {
  public:
    int minProcessingTime(vector<int> &processorTime, vector<int> &tasks) {
        sort(begin(processorTime), end(processorTime));
        sort(begin(tasks), end(tasks));
        int res = 0;
        for (int i = 0; i < tasks.size(); i++) {
            res = max(res, processorTime[i >> 2] + tasks[tasks.size() - i - 1]);
        }
        return res;
    }
};
