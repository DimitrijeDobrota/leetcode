class Solution {
  public:
    int minimumCost(int n, int m, const vector<int> &hCut, const vector<int> &vCut) const {
        int res = accumulate(begin(hCut), end(hCut), 0) + accumulate(begin(vCut), end(vCut), 0);

        for (const int a : hCut) {
            for (const int b : vCut) {
                res += min(a, b);
            }
        }

        return res;
    }
};
