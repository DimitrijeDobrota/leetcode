class Solution {
  public:
    int countSeniors(const vector<string> &details) const {
        int res = 0;

        for (const auto &detail : details) {
            if (detail[11] < '6') continue;
            if (detail[11] > '6' || detail[12] > '0') res++;
        }
        return res;
    }
};
