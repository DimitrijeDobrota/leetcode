class Solution {
  public:
    int maxWidthOfVerticalArea(const vector<vector<int>> &points) {
        vector<int> v;
        v.reserve(points.size());
        for (int i = 0; i < points.size(); i++)
            v.push_back(points[i][0]);
        sort(v.begin(), v.end());

        int maxi = 0;
        for (int k = 1; k < v.size(); k++)
            maxi = max(maxi, v[k] - v[k - 1]);
        return maxi;
    }
};
