#include <span>

class Solution {
  public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
        static int idx[100001];
        const int n = size(wage);

        iota(idx, idx + n, 0);
        sort(idx, idx + n,
             [&](int a, int b) { return (double)wage[a] / quality[a] < (double)wage[b] / quality[b]; });

        priority_queue<int> pq;
        double res = DBL_MAX, crnt = 0;
        for (const int i : std::span(idx, idx + n)) {
            crnt += quality[i];
            pq.push(quality[i]);
            if (size(pq) > k) crnt -= pq.top(), pq.pop();
            if (size(pq) == k) res = min(res, crnt * wage[i] / quality[i]);
        }

        return res;
    }
};
