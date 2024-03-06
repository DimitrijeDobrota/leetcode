class Solution {
  public:
    double maxAverageRatio(const vector<vector<int>> &classes, int extraStudents) const {
        typedef tuple<double, int, int> record;
        static const auto profit = [](int p, int t) { return (double)(p + 1) / (t + 1) - (double)p / t; };

        double res = 0;
        priority_queue<record, vector<record>> pq;
        for (const auto &c : classes) {
            pq.emplace(profit(c[0], c[1]), c[0], c[1]);
            res += (double)c[0] / c[1];
        }

        while (extraStudents--) {
            const auto [a, p, t] = pq.top();
            pq.pop();
            pq.emplace(profit(p + 1, t + 1), p + 1, t + 1);
            res += a;
        }

        return res / size(classes);
    }
};
