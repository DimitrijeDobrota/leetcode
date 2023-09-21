class Solution {
  public:
    int minCost(const string &colors, const vector<int> &neededTime) {
        int res = 0, prev = neededTime[0];
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] != colors[i - 1]) {
                prev = neededTime[i];
                continue;
            }
            if (neededTime[i] < prev)
                res += neededTime[i];
            else {
                res += prev;
                prev = neededTime[i];
            }
        }
        return res;
    }
};
