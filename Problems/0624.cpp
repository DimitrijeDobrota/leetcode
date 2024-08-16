class Solution {
  public:
    int maxDistance(vector<vector<int>> &arrays) const {
        int mini = arrays[0].front();
        int maxi = arrays[0].back();
        int res = 0;

        for (int i = 1; i < size(arrays); i++) {
            res = max({res, arrays[i].back() - mini, maxi - arrays[i].front()});
            mini = min(mini, arrays[i].front());
            maxi = max(maxi, arrays[i].back());
        }

        return res;
    }
};
