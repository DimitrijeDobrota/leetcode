class Solution {
  public:
    int largestAltitude(const vector<int> &gain) {
        int maxi = 0, crnt = 0;
        for (int n : gain)
            maxi = max(maxi, crnt += n);
        return maxi;
    }
};
