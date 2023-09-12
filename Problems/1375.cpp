class Solution {
  public:
    int numTimesAllBlue(const vector<int> &flips) {
        int right = 0, res = 0;
        for (int i = 0; i < flips.size(); ++i)
            res += (right = max(right, flips[i])) == i + 1;
        return res;
    }
};
