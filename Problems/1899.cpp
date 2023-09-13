class Solution {
  public:
    bool mergeTriplets(const vector<vector<int>> &triplets, const vector<int> &tgt) {
        bool a = false, b = false, c = false;
        for (const auto &tp : triplets) {
            if (tp[0] > tgt[0] || tp[1] > tgt[1] || tp[2] > tgt[2]) continue;
            if (tp[0] == tgt[0]) a = true;
            if (tp[1] == tgt[1]) b = true;
            if (tp[2] == tgt[2]) c = true;
        }
        return a && b && c;
    }
};
