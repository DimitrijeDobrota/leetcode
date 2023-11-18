class Solution {
  public:
    vector<long long> maximumEvenSplit(long long finalSum) const {
        if (finalSum % 2) return {};
        vector<long long> res;
        for (long long crnt = 2; finalSum >= crnt; crnt += 2) {
            res.push_back(crnt);
            finalSum -= crnt;
        }
        res.back() += finalSum;
        return res;
    }
};
