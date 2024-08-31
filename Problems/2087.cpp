class Solution {
  public:
    int minCost(const vector<int> &startPos, const vector<int> &homePos, const vector<int> &rowCosts,
                const vector<int> &colCosts) const {
        int i = startPos[0], j = startPos[1];
        int x = homePos[0], y = homePos[1];
        int res = 0;

        while (i != x) {
            i += i < x ? 1 : -1;
            res += rowCosts[i];
        }

        while (j != y) {
            j += j < y ? 1 : -1;
            res += colCosts[j];
        }

        return res;
    }
};
